#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7, MAXN = 3000;
#define nl '\n'
int R, C, c[MAXN+2][MAXN+2], p[MAXN+2];
void init() {
    p[0] = 1;
    for (int i=1; i<=MAXN; i++) {
        c[i][0] = c[i][i] = 1;
        p[i] = p[i-1] * 2 % MOD;
        for (int j=1; j<i; j++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
        }
    }
}
ll pw(ll b, ll exp) {
    ll ret = 1;
    while (exp) {
        if (exp&1) ret = ret * b % MOD;
        b = b * b % MOD;
        exp >>= 1;
    }
    return ret;
}
void solve(int tc) {
    cin >> R >> C;
    ll ans = 0;
    for (int i=0; i<=C; i++) {
        //At most C columns all have 1 - At most (C-1) columns all have 1 + ... ; OR
        //At least 0 columns empty - At least 1 column empty + At least 2 column empty etc.
        if (i&1) {
            ans = ((ans - pw(p[C-i] - 1LL, R) * c[C][i] % MOD) % MOD + MOD) % MOD;
        } else {
            ans = (ans + pw(p[C-i] - 1LL, R) * c[C][i] % MOD) % MOD;
        }
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); init(); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }