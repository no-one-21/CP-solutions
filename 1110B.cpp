//17571@nith.ac.in @Ankit Verma
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("O3")
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#ifndef ONLINE_JUDGE
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1) {
    cerr << name << " : " << arg1 << std :: endl;
}
template < typename Arg1, typename... Args >
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define debug(...)
#endif
#define n_l '\n'
template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(bool b) { return (b ? "true" : "false"); } string to_string(char c){ return string({c}); } template<size_t N> string to_string(bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgs(T...); }
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgs(__VA_ARGS__); cout << endl;
#define MOD 1000000007
#define MOD9 1000000009
#define ll long long
#define ull unsigned long long
#define gc getchar_unlocked
#define eps 1e-8
#define ms(s,n) memset(s,n,sizeof(s))
#define bolt ios::sync_with_stdio(false)
const double pie = 2 * acos(0.0);
#define prec(n) fixed<<setprecision(n)
#define eof (scanf("%d",&n))!=EOF
#define Unique(v) v.erase(unique(v.begin(), v.end()), v.end());
#define EraseSpace(s) s.erase( remove( s.begin(), s.end(), ' ' ), s.end() );
#define leftrotate(str, n) rotate(str.begin(), str.begin()+n, str.end());
#define rightrotate(str, n) rotate(str.begin(), str.begin()+str.size()-n, str.end());
#define pii pair <int, int> 
#define f(i,x,n) for(int i = x; i < n; i++)
#define fr(i,x,n) for(int i = x; i <= n; i++)
// Constants
constexpr int dx[] = { -1, 0, 1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
#define pb push_back
#define eb emplace_back
#define MP make_pair
#define all(v) v.begin(), v.end()
typedef pair<ll, ll> pll;
typedef vector<ll> vll; 
gp_hash_table<long long, int, custom_hash> smp;
int main()
{

    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    bolt;
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k; cin >> n >> m >> k;
    int ar[n];
    for (int i = 0; i < n; i++) {
    	cin >> ar[i];
    }
    int ans = (ar[n - 1] - ar[0]);
    vector <int> res;
    for (int i = 0; i < n - 1; i++) {
    	res.pb(ar[i] - ar[i + 1]);
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < k - 1; i++) {
    	ans += (res[i]);
    }
    cout << ans + k << endl;

    return 0;
}