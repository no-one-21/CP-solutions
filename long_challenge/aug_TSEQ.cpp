#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define ll long long
using namespace std;
const int N=100005;
const int M=2000005;
const int mo=1000000007;
int fac[M],inv[M],w[N];
void init(){
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,M-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,M-1) fac[i]=1ll*fac[i-1]*i%mo;
	For(i,1,M-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
}
int C(int x,int y){
	if (x<0||y<0||y>x) return 0;
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
struct node{
	int vl,vr,ql,qr,len,s[4];
	node(){}
	node(int v){
		s[0]=s[1]=s[2]=s[3]=1; len=1;
		vl=vr=v; ql=qr=(v==-2);
	}
	friend node operator +(const node &a,const node &b){
		node ans;
		ans.len=a.len+b.len;
		ans.vl=(a.ql==a.len?b.vl:a.vl);
		ans.vr=(b.qr==b.len?a.vr:b.vr);
		ans.ql=a.ql+(a.ql==a.len?b.ql:0);
		ans.qr=b.qr+(b.qr==b.len?a.qr:0);
		ans.s[0]=1ll*a.s[0]*b.s[0]%mo;
		ans.s[1]=1ll*a.s[1]*b.s[1]%mo;
		ans.s[2]=1ll*a.s[2]*b.s[2]%mo;
		ans.s[3]=1ll*a.s[3]*b.s[3]%mo;
		if (a.vr!=-2&&b.vl!=-2){
			ans.s[0]=1ll*ans.s[0]*C(b.vl-a.vr-1,a.qr+b.ql)%mo;
			ans.s[1]=1ll*ans.s[1]*C(a.vr-b.vl-1,a.qr+b.ql)%mo;
			ans.s[2]=1ll*ans.s[2]*C(b.vl-a.vr+a.qr+b.ql,a.qr+b.ql)%mo;
			ans.s[3]=1ll*ans.s[3]*C(a.vr-b.vl+a.qr+b.ql,a.qr+b.ql)%mo;
		}
		return ans;
	}
	node flip(){
		node ans;
		ans.len=len;
		For(i,0,3) ans.s[i]=s[i^1];
		ans.vl=vr; ans.vr=vl;
		ans.ql=qr; ans.qr=ql;
		return ans;
	}
};
node t[N*4];
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n,Q;
int dfn[N],ed[N];
int pos[N],top[N];
int sz[N],fa[N],dep[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs1(int x){
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			fa[e[i].to]=x;
			dep[e[i].to]=dep[x]+1;
			dfs1(e[i].to);
			sz[x]+=sz[e[i].to];
		}
}
void dfs2(int x,int tp){
	top[x]=tp;
	dfn[x]=++*dfn;
	pos[*dfn]=x;
	int k=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&sz[e[i].to]>sz[k])
			k=e[i].to;
	if (k) dfs2(k,tp);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=k)
			dfs2(e[i].to,e[i].to);
}
void build(int k,int l,int r){
	if (l==r){
		t[k]=node(w[pos[l]]-(w[pos[l]]<0));
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]+t[k*2+1];
}
void change(int k,int l,int r,int p,int v){
	if (l==r){
		t[k]=node(v-(v<0));
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
	t[k]=t[k*2]+t[k*2+1];
}
node ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y);
}
int getans(int x,int y,int A,int B,int op){
	node ansL(-2),ansR(-2);
	ansL.ql=ansL.qr=ansR.ql=ansR.qr=ansL.len=ansR.len=0;
	int X=x,Y=y;
	for (;top[x]!=top[y];x=fa[top[x]])
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
	int L=(dep[x]<dep[y]?x:y); x=X; y=Y;
	for (;top[x]!=top[L];x=fa[top[x]])
		ansL=ansL+ask(1,1,n,dfn[top[x]],dfn[x]).flip();
	ansL=ansL+ask(1,1,n,dfn[L],dfn[x]).flip();
	for (;top[y]!=top[L];y=fa[top[y]])
		ansR=ask(1,1,n,dfn[top[y]],dfn[y])+ansR;
	if (L!=y) ansR=ask(1,1,n,dfn[L]+1,dfn[y])+ansR;
	if (op&1) swap(A,B);
	if (op<=1){
		if (op==0) A--; else A++;
		if (op==0) B++; else B--;
	}
	ansL=node(A)+ansL+ansR+node(B);
	return ansL.s[op];
}
int main(){
	init();
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&w[i]);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs1(1);
	dfs2(1,1);
	build(1,1,n);
	while (Q--){
		char s[50];
		int x,y,A,B;
		scanf("%s%d%d",s+1,&x,&y);
		int len=strlen(s+1);
		if (len==6) change(1,1,n,dfn[x],y);
		if (len==10){
			scanf("%d%d",&A,&B);
			printf("%d\n",getans(x,y,A,B,s[1]=='I'?0:1));
		}
		if (len==14){
			scanf("%d%d",&A,&B);
			printf("%d\n",getans(x,y,A,B,s[5]=='I'?3:2));
		}
	}
}