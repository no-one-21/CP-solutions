#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		if(n%2==0)
			{
				ll maxi=1<<n;
				//cout<<maxi;
				ll chance=n/2;
				ll sum=0;
				for(ll i=1;i<=chance;i++)
				{
					ll once=maxi/(1<<(2*i));
					sum=sum+once;

				}
				cout<<sum<<" "<<maxi<<" ";
			}
			else
			{
				ll maxi=1<<n;
				ll chance=n/2+1;
				ll sum=0;
				for(ll i=1;i<=chance;i++)
				{
					ll once=maxi/(1<<((2*i)-1));
					sum=sum+once;
				}
				sum=maxi-sum;
				cout<<sum<<" "<<maxi<<" ";

			}
	}
}