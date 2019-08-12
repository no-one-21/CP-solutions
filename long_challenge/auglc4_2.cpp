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
	int c[n+1],h[n+1];	
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
		cin>>h[i];
	int res[n+1]={0};
	for(int i=1;i<=n;i++)
		for(int j=max(1,i-c[i]);j<=min(n,i+c[i]);j++)
			res[j]++;
	// for(int x:res)
	// 	cout<<x<<" "<<endl;
	bool f=1;
	for(int i=1;i<=n && f!=0;i++)
		if(res[i]<h[i])
			f=0;
	if(f)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}

return 0;
}