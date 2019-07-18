#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
  string a;
  string b;
  cin>>a;
  cin>>b;
  string c;
  cin>>c;
  string d= a+b;
  sort(d.begin(),d.end());
  sort(c.begin(),c.end());
  ll count=0;
  if(c.length()==d.length()){
    for(ll i=0;i<c.length();i++){
      if(c[i]!=d[i])
      count++;
    }
    if(count>0)
    cout<<"NO";
    else
    cout<<"YES";
  }
  else
  cout<<"NO";
}
