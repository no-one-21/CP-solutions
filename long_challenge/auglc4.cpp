/******************************************
* AUTHOR : Ashish Joshi* 
* INSTITUTION : NIT Hamirpur *
******************************************/
#include <bits/stdc++.h>
#include<functional>
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


int increment(int x) {  return (x+1); } 

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
	int c[n+1],h[n+1];
	int res[n+1]={0};
	int temp[n+1];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
		cin>>h[i];

	for(int i=1;i<=n;i++)
	{	temp[i]=1;
		// cout<<res[i];
	}

	int f1[n+1],f2[n+1];
	for(int i=1;i<=n;i++)
	{
	 	f1[i] = max(1,i-c[i]);
		f2[i] = min(n,i+c[i]);
		// make_pair <int,int>{(1,i-c[i]);j<=min(n,i+c[i]);j++)
			// res[j]++;
	}

	for(int i=1;i<=n;i++)
	{
		transform(temp+min(n+1,f1[i]-1),temp+min(n+1,f2[i]+1),res,res,plus<int>());
		// for(int j=1;j<=n;j++)
		// 	cout<<res[j]<<" ";
		// 	cout<<endl;
	}
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		if(res[i]<h[i])
		{	
			f=0;
			break;
		}
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<res[i]<<" ";
	// cout<<endl;
	if(f)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}
return 0;
}