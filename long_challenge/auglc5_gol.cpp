/******************************************
* AUTHOR : Ashish Joshi* 
* INSTITUTION : NIT Hamirpur *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define MOD 1000000007
#define dd double
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second

vector<int>v[100001];

int main() {
ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//ios_base& scientific (ios_base& str);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n+1],b[n+1];
        a[0]=0;
        b[0]=0;
        map<ll,vector<ll>>freq;
        freq[0].push_back(0);
        ll res=0;
        for(ll i=1;i<=n;i++)
        {
        	cin>>a[i];
            b[i]=b[i-1]^a[i];
            freq[b[i]].push_back(i);
        }
       map<ll,vector<ll>>::iterator itr;
        for(itr=freq.begin();itr!=freq.end();++itr){
            if(itr->second.size()>1){
                ll sum=0;
                ll k =itr->second.size();
                for(ll j=0;j<itr->second.size();j++){
                    sum+=(j*(itr->second[j]))-(itr->second.size()-1-j)*(itr->second[j]);
                }
                sum-=(k*(k-1))/2;
                res+=sum;
            }
        }
        cout<<res<<endl;

    }

return 0;
}