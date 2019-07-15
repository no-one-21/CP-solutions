#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
  ll n,m;
  cin>>n>>m;
  ll a[m];
  for(ll i=0;i<m;i++){
    cin>>a[i];
  }
  ll time=a[0]-1;
  for(ll i=0;i<m-1;i++){
    if(a[i+1]-a[i]>0){
      time=time+a[i+1]-a[i];
    }else if(a[i+1]-a[i]<0){
      time+=n-a[i]+a[i+1];
    }
  //  cout<<"time"<<time;
  }
  cout<<time;
}
