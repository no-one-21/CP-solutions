#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
typedef long long ll;
using namespace std;
int main(){
  ll n ,l;
  cin>>n>>l;
  ll a[n];
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  double start=a[0]-0;
  double end=l-a[n-1];
  double maxi=INT_MIN;
  for(ll i=1;i<n;i++){
    if(a[i]-a[i-1]>maxi)
    maxi=a[i]-a[i-1];
  }
  if(start>=maxi/2 && start>end)
  cout<<fixed<<setprecision(9)<<start;
  else if(end>=maxi/2 && end>start)
  cout<<fixed<<setprecision(9)<<end;
  else
  cout<<fixed<<setprecision(9)<<maxi/2;
}
