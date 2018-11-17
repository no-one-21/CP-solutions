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
		map<ll,ll>freq;
		//vector<ll>ele;
		//vector<ll>ele2;
		ll ele[n];
		ll ele2[n];
		for(ll i=1;i<=n;i++)
		{
			ll a;
			cin>>a;
			//ele.push_back(a);
			//ele2.push_back(a);
			ele[i]=a;
			ele2[i]=a;
			freq[a]++;

		}
		sort(ele2 +1,ele2+1+n);
		ll k=0;

		map<ll,ll>::iterator point;
		for(point=freq.begin();point!=freq.end();point++)
		{
			//cout<<point->first<<"\n";
			if(point->second>1)
			{
				k=0;
				//cout<<point->second<<"\n";
				for(ll i=1;i<=n;i++)
				{
					if(ele[i]==point->first)
					{
						//cout<<ele[i]<<""<<i<<" "<<point->first<<"\n";
						bool p=binary_search(ele2+1,ele2+1+n,i);
						if(p )
							k++;
						//cout<<k<<"\n";
						if(k>=2)
							break;

					}
				}
				//if(k>=2)
				//	break;
			}
			if(k>=2)
				break;
		}
		if(k>=2)
			cout<<"Truly Happy"<<"\n";
		else
			cout<<"Poor Chef"<<"\n";
	}
}