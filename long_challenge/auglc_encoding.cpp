#include <iostream>


using namespace std;
typedef long long ll;
const int max_D = 100005;
const ll mod = 1000000007;

char L[max_D], R[max_D];
ll tens[max_D], nines[max_D];
int S[10] = {0,1,3,6,10,15,21,28,36,45};

void prepare() {
    tens[0] = 1;
    nines[0] = 0;
    for (int i=1; i<max_D; ++i) {
        tens[i] = tens[i-1]*10 % mod;
        nines[i] = tens[i] - tens[i-1];
        if (nines[i] < 0) nines[i] += mod;
    }
}

void decrement(char* num, int N) {
    for (int i=N-1; i>=0; --i) {
        if (num[i] == '0')
            num[i] = '9';
        else {
            num[i] -= 1;
            break;
        }
    }
}

ll calc_sum(const char* num, int N) {
    int start = 0;
    int d;
    do {
        d = num[start] - '0';
        ++start;
    } while (d == 0);
    ll res = (tens[N-start]*S[d-1] % mod) * tens[N-start] % mod;
    ll X = 0;
    int d1 = d;
    for (int n = N-1-start, i=start; n >=0; --n, ++i) {
        d = num[i] - '0';
        ll tmp = (X*S[9] + tens[n]*(d1*S[9] - S[d1] + ((d>0)?S[d-1]:0))) % mod;
        if (tmp < 0)
            tmp += mod;
        if (d1 >= d)
            tmp = (tmp + d1*tens[n]) % mod;
        tmp = tmp*tens[n] % mod;
        res += tmp;
        if (res >= mod)
            res -= mod;

        X = (X + d1*nines[n]) % mod;
        d1 = d;
    }
    ll Y = 1;
    for (int n = N-1, i=0; n>=0; --n, ++i) {
        d = num[n]-'0';
        if (n==0 or num[n] != num[n-1])
            res = (res + (Y*tens[i] % mod) * d) % mod;
        Y = (Y + tens[i]*d) % mod;
    }
    return res;
}

int main() {
    prepare();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, NL, NR;
    cin >> T;
    for (int t=0; t<T; ++t) {
        cin >> NL;
        cin >> L;
        cin >> NR;
        cin >> R;

        ll res = calc_sum(R, NR);
        if (NL > 1 or L[0] != '1') {
            decrement(L, NL);
            res -= calc_sum(L, NL);
            if (res < 0)
                res += mod;
        }
        cout << res << "\n";
    }
}