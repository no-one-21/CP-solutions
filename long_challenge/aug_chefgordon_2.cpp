#include<bits/stdc++.h>
using namespace std;

#define MX1       100005
#define MX2       15002
#define IMX       1000000000
#define BASE1     31LL
#define BASE2     59LL
#define MOD1      1000000007LL
#define MOD2      1000000009LL
#define LL        long long int
#define PII       pair<int,int>
#define PIP       pair<int,PII>
#define PLI       pair<LL,int>
#define PIL       pair<int,LL>
#define PLL       pair<LL,LL>
#define PDD       pair<double,double>
#define PPI       pair<PLL,int>
#define PCI       pair<char,int>
#define LFT(x)    (x<<1)
#define RHT(x)    ((x<<1)+1)
#define MID(x,y)  ((x+y)>>1)
#define FAST      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

inline int setBit(int mask,int pos){    return  (mask | (1<<pos));}
inline int resetBit(int mask,int pos){  return  (mask & ~(1<<pos));}
inline bool checkBit(int mask,int pos){ return  (bool)(mask & (1<<pos));}
#define PC(x)   __builtin_popcount(x)

vector<int>vec[MX1];
int n,perm[5];
int tree[MX1];

void update(int indx,int x)
{
    while(indx<=n)
    {
        tree[indx] += x;
        indx += (indx & (-indx));
    }
    return;
}

int query(int indx)
{
    int ans = 0;
    while(indx>0)
    {
        ans += tree[indx];
        indx -= (indx & (-indx));
    }
    return  ans;
}

PIL DFS(int s,int p,int flag)
{
    int unwanted1,unwanted2,unwanted3,unwanted4;
    if(!flag)
    {
        unwanted1 = unwanted2 = query(s);
    }
    else if(flag==1)
    {
        unwanted1 = unwanted2 = query(s);
        unwanted3 = unwanted4 = query(n) - query(s);
    }
    else
    {
        unwanted1 = unwanted2 = query(n) - query(s);
    }
    update(s, 1);

    LL sub = 0;
    int subTreeSize = 1;
    for(int i=0; i<vec[s].size(); i++)
    {
        if(vec[s][i]==p)    continue;

        PIL pr = DFS(vec[s][i], s, flag);
        int x = pr.first;
        subTreeSize += x;
        sub += pr.second;

        if(!flag)
        {
            int y = query(s-1);
            int z = y - unwanted2;
            unwanted2 = y;
            x -= z;

            LL tmp = x;
            tmp = (tmp * (tmp - 1LL))/2LL;
            sub += tmp;
        }
        else if(flag==1)
        {
            int y = query(s-1);
            int z = query(n) - query(s);
            LL t1 = y - unwanted2;
            LL t2 = z - unwanted4;
            unwanted2 = y;
            unwanted4 = z;
            sub += (t1 * t2);
        }
        else
        {
            int y = query(n) - query(s);
            int z = y - unwanted2;
            unwanted2 = y;
            x -= z;

            LL tmp = x;
            tmp = (tmp * (tmp - 1LL))/2LL;
            sub += tmp;
        }
    }

    if(!flag)
    {
        int y = s - 1;
        y = y - (query(s-1) - unwanted1);
        int x = n - subTreeSize;
        x -= y;

        LL tmp = x;
        tmp = (tmp * (tmp - 1LL))/2LL;
        sub += tmp;
    }
    else if(flag==1)
    {
        int y = s - 1;
        y = y - (query(s-1) - unwanted1);
        int z = n - s;
        z = z - (query(n) - query(s) - unwanted3);

        LL t1 = y;
        LL t2 = z;
        sub += (t1 * t2);
    }
    else
    {
        int y = n - s;
        y = y - (query(n) - query(s) - unwanted1);
        int x = n - subTreeSize;
        x -= y;

        LL tmp = x;
        tmp = (tmp * (tmp - 1LL))/2LL;
        sub += tmp;
    }

    return  PIL(subTreeSize, sub);
}

void solve(int flag)
{
    LL ans = 0;
    if(!flag)   /// _ 1 _
    {
        for(int i=1; i<=n; i++)
        {
            LL tmp = n - i - 1;
            tmp = (tmp * (tmp + 1LL))/2LL;
            ans += tmp;
        }
    }
    else if(flag==1)    /// _ 2 _
    {
        for(int i=1; i<=n; i++)
        {
            LL t1 = i - 1;
            LL t2 = n - i;
            t1 *= t2;
            ans += t1;
        }
    }
    else    /// _ 3 _
    {
        for(int i=1; i<=n; i++)
        {
            LL tmp = i - 2;
            tmp = (tmp * (tmp + 1LL))/2LL;
            ans += tmp;
        }
    }

    ans -= DFS(1, -1, flag).second;
    cout<<ans<<endl;
}

void clr()
{
    memset(tree,0,sizeof(tree));
    for(int i=1; i<=n; i++) vec[i].clear();
}

int main()
{
    FAST;
    //freopen("out.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t,x,y;

    cin >> t;
    while(t--)
    {
        cin >> n;
        clr();
        for(int i=0; i<3; i++)  cin >> perm[i];
        for(int i=1; i<n; i++)
        {
            cin >> x >> y;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }

        if(perm[1]==1)  solve(0);
        else if(perm[1]==2) solve(1);
        else    solve(2);
    }
    return  0;
}
