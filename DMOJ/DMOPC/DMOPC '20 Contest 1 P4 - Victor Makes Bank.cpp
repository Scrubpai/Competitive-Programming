#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))

const int MOD = 1e9 + 7;
ll N, K, T, C;

struct matrix {
    ll a[105][105];
    matrix() { ms(a, 0); }
    matrix operator* (const matrix& other) {
        matrix ret;
        for (int i = 0; i <= T; i++) {
            for (int j = 0; j <= T; j++) {
                for (int k = 0; k <= T; k++) {
                    ret.a[i][j] = (ret.a[i][j] + a[i][k] * other.a[k][j]) % MOD;
                }
            }
        }
        return ret;
    }
};

matrix pwmd(matrix base, ll exp) {
    matrix ret;
    for (int i = 0; i <= T; i++) ret.a[i][i] = 1;
    while (exp > 0) {
        if (exp % 2 == 1) ret = ret * base;
        base = base * base; exp /= 2;
    }
    return ret;
}

void solve (int tc) {

    cin >> N >> K >> T >> C;
    matrix base, ans;
    base.a[0][T] = K;
    base.a[T][T] = 1;
    for (int i = 1; i <= T; i++) base.a[i][i - 1] = 1;
    ans = pwmd(base, N - 1);
    ll res = (2 * C % MOD * ans.a[T][T]) % MOD;
    for (int i = 0; i < T; i++) {
        res = (res + C * ans.a[i][T] % MOD) % MOD;
    }
    cout << res << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}