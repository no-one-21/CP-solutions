#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long UL;
typedef unsigned char UC;
typedef unsigned int UI;
typedef pair<int,int> II;
typedef vector<II> VII;

const int kMod = 998244353;

int fast_power(int a, int p) {
	if ((p == 1) || (a == 1) || (a == 0))
		return a;

	LL res = 1;
	LL factor = a;
	while(p) {
		if (p % 2)
			res = res*factor%kMod;
		p /= 2;
		if (p)
			factor = factor*factor%kMod;
	}
	return res;
}

int inv_mod(int a)
{
	int x(0), y(1), u(1), v(0), e(kMod), f(a);
	int c,d,q,r;
	while(f != 1)
	{
		q = e/f;
		r = e%f;
		c = x-q*u;
		d = y-q*v;
		x = u; y = v;
		u = c; v = d;
		e = f; f = r;
	}
	return (u+kMod)%kMod;
}

int det(vector<vector<int>>& mat)
{
	const int n = mat.size();
	int num1, num2, det(1), index, total(1);
	vector<int> temp(n+1);

	for(int i=0; i<n; ++i) {
		index = i;
		while(mat[index][i] == 0 && index < n) {
			index++;
		}
		if(index == n) continue;
		if(index != i) {
			for(int j = 0; j < n; j++) {
				swap(mat[index][j],mat[i][j]);
			}
			if (((index-i)&1) && det) {
				det = -det + kMod;
			}
		}

		for(int j=0; j<n; ++j) {
			temp[j] = mat[i][j];
		}
		for(int j=i+1; j<n; ++j) {
			num1 = temp[i];
			num2 = mat[j][i];
			for(int k=0; k<n; ++k) {
				mat[j][k] = (LL(num1)*mat[j][k]%kMod - LL(num2)*temp[k]%kMod + kMod)%kMod;
			}
			total = LL(total)*num1%kMod;
		}
	}

	for(int i = 0; i < n; i++) {
		det = LL(det)*mat[i][i]%kMod;
	}
	return LL(det)*inv_mod(total)%kMod;
}

int solve_bf(const int N, const int K, const VII& edges) {
	const int NK = N*K;
	vector<int> degs(N, NK-1);
	const int M = edges.size();
	for(int i=0; i<M; ++i) {
		degs[edges[i].first] -= 1;
		degs[edges[i].second] -= 1;
	}

	vector<vector<int>> mat(NK, vector<int>(NK, -1));
	for(int k=0; k<K; ++k) {
		for(int i=0; i<N; ++i) {
			mat[i+N*k][i+N*k] = degs[i];
		}
		for(int i=0; i<M; ++i) {
			const int u = edges[i].first;
			const int v = edges[i].second;
			mat[u+N*k][v+N*k] = 0;
			mat[v+N*k][u+N*k] = 0;
		}
	}

	mat.pop_back();
	for(int i=0; i<mat.size(); ++i) {
		mat[i].pop_back();
	}

	return det(mat);
}

void transform(vector<vector<int>>& mat) {
	const int n = mat.size();
	for(int i=0; i<n-1; ++i) {
		for(int j=0; j<n; ++j) {
			mat[i][j] = (mat[i][j] + kMod - mat.back()[j])%kMod;
		}
	}
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n-1; ++j) {
			mat[i][j] = (mat[i][j] + kMod - mat[i].back())%kMod;
		}
	}
}

int solve(const int N, const int K, const VII& edges) {
	const int md = (LL(N)*K-1)%kMod;
	vector<int> degs(N, md);
	const int M = edges.size();
	for(int i=0; i<M; ++i) {
		degs[edges[i].first] -= 1;
		degs[edges[i].second] -= 1;
	}
	for(int i=0; i<N; ++i) {
		if (degs[i] < 0) {
			degs[i] += kMod;
		}
	}
	vector<vector<int>> mat(N, vector<int>(N, kMod-1));
	for(int i=0; i<N; ++i) {
		mat[i][i] = degs[i];
	}
	for(int i=0; i<M; ++i) {
		const int u = edges[i].first;
		const int v = edges[i].second;
		mat[u][v] = 0;
		mat[v][u] = 0;
	}
	transform(mat);
	mat.pop_back();
	for(int i=0; i<mat.size(); ++i) {
		mat[i].pop_back();
	}
	const LL mult = (K > 2) ? fast_power(K, K-2) : 1;
	return fast_power(det(mat), K)*mult%kMod*inv_mod(N*N)%kMod;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int T, N, M, K, u, v;
   cin >> T;
	for(int t=0; t<T; ++t) {
		cin >> N >> M >> K;
		VII edges(M);
		for(int i=0; i<M; ++i) {
			cin >> u >> v;
			edges[i] = II(u-1, v-1);
		}
		int ans = solve(N, K, edges);
		cout << ans << "\n";
	}
   return 0;
}
