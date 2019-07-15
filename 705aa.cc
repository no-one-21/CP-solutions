#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
  ll n;
  cin>>n;
  if(n%2==0){
    while(n>0){
      if(n==1)
      cout<<"I love it";
      else{
      if(n%2==0)
      cout<<"I hate that ";
      else
      cout<<"I love that ";
    }
    n=n-1;}
  }else{
    while(n>0){
      if(n==1)
      cout<<"I hate it";
      else{
      if(n%2==0)
      cout<<"I love that ";
      else
      cout<<"I hate that ";
    }
    n=n-1;}
  }
}
