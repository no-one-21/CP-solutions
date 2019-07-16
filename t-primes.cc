#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
bool check_square(int n){
  double root = sqrt(n);
  if(root==int(root))
  return true;
  else
  return false;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(ll i=0;i<n;i++){
      cin>>a[i];
    }
    ll prime[1000000];
    for(ll i=0;i<1000000;i++){
      prime[i]=1;
    }

    for(ll p=2;p*p<1000000;p++){
      if(prime[p]==1){
        for(ll j=p*p;j<1000000;j=j+p){
          prime[j]=0;
        }
      }
    }
//cout<<prime[999983]<<" nnn"<<" ";
  //  cout<<primes[9];
    for(ll i=0;i<n;i++){
      cout<<"root"<<sqrt(a[i]);
      if(sqrt(a[i])== int(sqrt(a[i])) && a[i]!=1){
        int root = sqrt(a[i]);
        cout<<"root"<<root;
        if(prime[root]==1)
        cout<<"YES"<<"\n";
        else
        cout<<"NO"<<"\n";
      }
      else
      cout<<"NO"<<"\n";
    }
}
