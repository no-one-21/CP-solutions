/******************************************
* AUTHOR : Ashish Joshi* 
* INSTITUTION : NIT Hamirpur *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
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

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//ios_base& scientific (ios_base& str);
int t;
cin>>t;
while(t--)
{
	int n;
	cin>>n;
	int a[n],xr[n];
	// for(int i=0;i<n;i++)
	// 	cin>>a[i];
	vector<int> g1; 
  
    for (int i = 1; i <= n; i++) 
    	int temp;
    	cin>>temp;
        g1.push_back(temp);  

	xr[0]=a[0];
	map<int,int> xrt;
	xrt[a[0]]++;
	
	for(int i=1;i<n;i++)
	{
		xr[i]=xr[i-1]^a[i];
		// if(xr[i]==0)
		// {

		// }
		// else if(xrt.count(xr[i])!=0)
		// {

		// }
		xrt[xr[i]]++;
	}
	for(auto i=xrt.begin();i!=xrt.end();++i)
		cout<<i->first<<" "<<i->second<<endl;




	for(int i=0;i<n;i++)
		cout<<xr[i]<<" ";



}

return 0;
}