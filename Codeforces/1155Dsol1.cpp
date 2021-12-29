#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3e5+5;
#define nl '\n'
#define inf 0x3f3f3f3f3f3f3f3f
int n; ll a[MM], x, dp[MM][3][3];
void solve(int tc) {
    cin >> n >> x; memset(dp, -inf, sizeof(dp)); dp[0][0][0]=0;
    for (int i=0; i<=n; i++) {
        if (i<n) cin >> a[i];
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                if (k<2) dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][j][k]);
                if (j<2) dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]);
                if (i<n) dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k] + (j == 1 ? a[i] : 0) * 1ll * (k == 1 ? x : 1));
            }
        }
    }
    cout << dp[n][2][2] << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }