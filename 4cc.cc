#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
  ll n;
  cin>>n;
  map <string,int> freq;
  for(ll i=0;i<n;i++){
    string s;
    cin>>s;
    if(freq[s]==0){
      cout<<"OK"<<"\n";
      freq[s]++;
    }
    else if(freq[s]>0){
      freq[s]++;
      int a = freq[s];
      cout<<s<<a-1<<"\n";
      string b= s;
      b=b+to_string(a-1);
      freq[b]++;
    }
  }
}
