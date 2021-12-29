#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MM = 2e5 + 5;
const int MOD = 998244353;

ll pwmd(ll b, ll exp) {
    ll ret = 1;
    while (exp > 0) {
        if (exp % 2 == 1) ret = (ret * b) % MOD;
        exp /= 2;
        b = (b * b) % MOD;
    }
    return ret;
}

int n, m, d[MM]; ll psa[MM];

void solve(int tc) {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> d[i];
    sort(d + 1, d + 1 + n);
    for (int i = 1; i <= n; i++) psa[i] = (psa[i-1] + d[i]) % MOD;
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        int pos = lower_bound(d + 1, d + 1 + n, b) - (d + 1) + 1;
        int big = n - pos + 1, small = pos - 1;
        if (big < a) { cout << 0 << nl; continue; }
        //linearity of expectation
        //big monsters: (big - a) / big
        ll Pbig = (1LL * (big - a) % MOD * pwmd(big, MOD - 2) % MOD) % MOD;
        //small monsters: (big + 1 - a) / (big + 1)
        // a "bad" positions
        // big + 1 - a "good" positions -- deals damage
        ll Psmall = (1LL * (big + 1 - a) % MOD * 1LL * pwmd(big + 1, MOD - 2) % MOD) % MOD;
        ll ans = ((1LL * (psa[n] - psa[pos-1] + MOD) * Pbig) % MOD) % MOD + ((1LL * psa[pos-1] * Psmall) % MOD) % MOD;
        cout << ans % MOD << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}