#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))

const int MOD = 1e9 + 7;
ll n;

struct matrix {
    ll a[2][2];
    matrix() { ms(a, 0); }
    matrix operator* (const matrix& other) {
        matrix ret;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    ret.a[i][j] = (ret.a[i][j] + a[i][k] * other.a[k][j]) % MOD;
                }
            }
        }
        return ret;
    }
};

matrix pwmd(matrix base, ll exp) {
    matrix ret;
    for (int i = 0; i < 2; i++) ret.a[i][i] = 1;
    while (exp > 0) {
        if (exp % 2 == 1) ret = ret * base;
        base = base * base; exp /= 2;
    }
    return ret;
}

void solve(int tc) {

    cin >> n;
    matrix x; x.a[0][1] = 1; x.a[1][0] = 1; x.a[1][1] = 1;
    matrix ans = pwmd(x, n-1);
    cout << ans.a[1][1] % MOD << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}