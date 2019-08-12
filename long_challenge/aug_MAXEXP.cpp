#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#define TASK "cache"
#pragma comment(linker, "/STACK:1108864220")
#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <functional>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <complex>
using namespace std;

const int MOD = 1000000007;
const int INF = 1000000000;
const double EPS = 1e-9;
const int HASH_POW = 29;
const long double PI = acos(-1.0);
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

long long nextLong(long long l, long long r) {
	uniform_int_distribution <long long> foo(l, r);
	return foo(rnd);
}

double nextDouble(double l, double r) {
	uniform_real_distribution <double> foo(l, r);
	return foo(rnd);
}

double workTime() {
	return double(clock()) / CLOCKS_PER_SEC;
}

void myReturn(int code = 0) {
#ifdef MYDEBUG
	cout << "\nTime = " << fixed << setprecision(3) << workTime() << endl;
#endif
	exit(code);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifdef MYDEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	/*freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);*/
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
#endif

	int CASE;
	scanf("%d", &CASE);
	while (CASE--) {
		int n;
		scanf("%d", &n);
		vector <int> kX100(n), cX100(n);
		for (int i = 0; i < n; ++i) {
			char s[20];
			scanf("%s", s);
			int len = strlen(s), foo = 0;
			for (int j = 0; j < len; ++j) {
				if ('0' <= s[j] && s[j] <= '9') {
					foo = 10 * foo + (s[j] - '0');
				}
			}
			if (s[0] == '-') {
				foo = -foo;
			}
			kX100[i] = foo;
		}
		for (int i = 0; i < n; ++i) {
			char s[20];
			scanf("%s", s);
			int len = strlen(s), foo = 0;
			for (int j = 0; j < len; ++j) {
				if ('0' <= s[j] && s[j] <= '9') {
					foo = 10 * foo + (s[j] - '0');
				}
			}
			if (s[0] == '-') {
				foo = -foo;
			}
			cX100[i] = foo;
		}

		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			sum -= cX100[i] * 1ll * kX100[i];
		}
		if (sum > 0) {
			printf("-1\n");
			continue;
		}
		long double S = -sum / 10000.0;

		long double ans = 0.0;
		for (int i = 0; i < n; ++i) {
			ans += 100.0 / kX100[i];
		}
		ans *= S;
		ans = sqrt(ans);
		printf("%.5Lf", ans);

		long double coef = 0.0;
		for (int i = 0; i < n; ++i) {
			coef += 100.0 / kX100[i];
		}
		for (int i = 0; i < n; ++i) {
			long double X = 100.0*S / (kX100[i] * coef);
			printf(" %.5Lf", X*100.0/kX100[i] - cX100[i]/100.0);
		}
		printf("\n");
	}

	myReturn();
}