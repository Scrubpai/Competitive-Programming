#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n, m, b, mod, a[501], dp[2][501][501];
void solve(int tc) {
    cin >> n >> m >> b >> mod;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0][0] = 1;
    for (int p = 1; p <= n; p++) {
        int i = p&1, i2 = i^1;
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= b; k++) {
                dp[i][j][k] = dp[i2][j][k] % mod;
                if (j > 0 && k - a[p] >= 0) dp[i][j][k] = (dp[i][j][k] + dp[i][j-1][k-a[p]]) % mod;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= b; i++) ans = (ans + dp[n&1][m][i]) % mod;
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}