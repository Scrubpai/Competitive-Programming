#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))

const int MOD = 1e9 + 7;
int n;
struct matrix {
    ll a[51][51];
    matrix() { ms(a, 0); }
    matrix operator* (const matrix& other) {
        matrix ret;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    ret.a[i][j] = (ret.a[i][j] + a[i][k] * other.a[k][j]) % MOD;
                }
            }
        }
        return ret;
    }
};
ll k;
matrix pwmd(matrix b, ll exp) {
    matrix ret;
    for (int i = 0; i < n; i++) ret.a[i][i] = 1;
    while (exp > 0) {
        if (exp % 2 == 1) ret = ret * b;
        b = b * b; exp /= 2;
    }
    return ret;
}

void solve (int tc) {

    cin >> n >> k; matrix x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x.a[i][j];
        }
    }
    matrix ans = pwmd(x, k);
    ll val = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            val = (val + ans.a[i][j]) % MOD;
        }
    }
    cout << val << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}