// aarsh01rsh@gmail.com
// Aarsh Sharma
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template < typename Arg1, typename... Args >
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}
#else
#define trace(...)
#endif
#define f(i, x, n) for (int i = x; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define pb push_back
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long int ll;
#define int ll
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vll;

const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;
const ll N = 1e5 + 10;

int32_t main() {
	fast_io();

	int n, q; cin >> n >> q;
	deque <int> d;
	f (i, 0, n) {
		int temp; cin >> temp;
		d.push_back(temp);
	}
	vector<pll> ans;
	int maxm = *max_element(all(d));
	for (int i = 0;; i++) {
		int a = d.front();
		d.pop_front();
		int b = d.front();
		d.pop_front();
		ans.push_back({a, b});
		if (a == maxm) {
			d.push_front(b);
			d.push_front(a);
			break;
		}
		if (a > b) {
			d.push_front(a);
			d.push_back(b);
		} else {
			d.push_front(b);
			d.push_back(a);
		}
	}
	int fin[n], i = 0;
	for (auto &it : d) {
		fin[i] = it;
		i++;
		trace(it);
	}
	int len = ans.size();
	trace(len);
	while (q--) {
		int idx; cin >> idx;
		if (idx <= len) {
			cout << ans[idx-1].F << " " << ans[idx-1].S << "\n";
		} else {
			int ti = (idx - len)%(n-1);
			cout << fin[0] << " " << fin[ti+1] << "\n";
		}
	}

	return 0;
}