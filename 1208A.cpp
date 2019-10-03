#include <bits/stdc++.h>
using namespace std;

int a, b;

int main()
{
  int t; cin >> t;
  while (t--) {

    int n; cin >> a >> b >> n;
    // printf("%d", fib(n));
    switch (n%3)
    {
      case 0:
        cout << a << endl;
        break;
      case 1:
        cout << b << endl;
        break;
      case 2:
        cout << (a^b) << endl;
        break;
      
      default:
        break;
    }
  }
  return 0;
}