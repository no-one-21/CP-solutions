#include<cstdio>
const int MaxN=100010;
int N,p[3],B[MaxN];
struct edge{int to;edge*next;}E[MaxN*2],*ne=E,*fir[MaxN];
void link(int u,int v){*ne=(edge){v,fir[u]};fir[u]=ne++;}
long long ans;
long long f(int lt,int gt){return p[1]==1?gt*(gt-1ll)/2:p[1]==2?1ll*lt*gt:lt*(lt-1ll)/2;}
void ins(int i){for(;i<=N;i+=i&-i)B[i]++;}
int qry(int i){int s=0;for(;i;i-=i&-i)s+=B[i];return s;}
void dfs(int i,int fa){
	int lt=i-1,gt=N-i;
	ans+=f(lt,gt);
	ins(i);
	for(edge*e=fir[i];e;e=e->next)if(e->to!=fa){
		int l=qry(i),g=qry(N); 
		dfs(e->to,i);
		l=qry(i)-l;g=qry(N)-g-l;
		ans-=f(l,g);
		lt-=l;gt-=g;
	}
	ans-=f(lt,gt);
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&N,p,p+1,p+2);
		for(int i=0;i<=N;i++)fir[i]=0,B[i]=0;ne=E;
		for(int i=1,u,v;i<N;i++){
			scanf("%d%d",&u,&v);
			link(u,v);link(v,u);
		}
		ans=0;
		dfs(1,0);
		printf("%lld\n",ans);
	}
}