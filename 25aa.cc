#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
  ll n;
  cin>>n;
  ll arr[n];
  for(ll i=0;i<n;i++){
    cin>>arr[i];
  }
  ll index;
  for(ll i=1 ; i<=n-1;i++){
    ll a = arr[i-1]%2;
    ll b = arr[i]%2;
    ll c = arr[i+1]%2;
    if(a==b&&a!=c){
      cout<<i+1+1;
      break;
    }else if(a==c && a!=b){
      cout<<i+1;
      break;
    }else if(b==c && a!=b){
      cout<<i-1+1;
      break;
    }
  }
}
