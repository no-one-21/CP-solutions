#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
  set<int> shoes;
  ll a,b,c,d;
  for(int i=0;i<4;i++){
    int s;
    cin>>s;
    shoes.insert(s);
  }
  cout<<4-shoes.size();
}
