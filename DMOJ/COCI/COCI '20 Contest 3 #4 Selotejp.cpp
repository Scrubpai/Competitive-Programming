#include <bits/stdc++.h>
using namespace std;
const int MM = 1<<10;
#define nl '\n'
#define INF 0x3f3f3f3f
int n, m, dp[MM][11][MM+5], a[MM][11];
void solve(int tc) {
    cin >> n >> m;
    memset(dp, INF, sizeof(dp));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char c; cin >> c;
            a[i][j] = (c == '#');
        }
    }
    int ans = 1e9;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int mask=0; mask<(1<<m); mask++) {
                if (i==0&&j==0) { dp[i][j][mask]=a[0][0]; continue; }
                int r = i, c = j-1;
                if (j==0) r=i-1, c=m-1;
                if (!a[i][j]) dp[i][j][mask]=dp[r][c][mask];
                else {
                    if (!(mask&(1<<j))) {
                        if (j==0 || !a[i][j-1] || (mask&(1<<(j-1)))) dp[i][j][mask] = min(dp[r][c][mask], dp[r][c][mask^(1<<j)]) + 1;
                        else dp[i][j][mask] = min(dp[r][c][mask], dp[r][c][mask^(1<<j)]);
                    } else {
                        if (i==0 || !a[i-1][j]) dp[i][j][mask] = min(dp[r][c][mask], dp[r][c][mask^(1<<j)]) + 1;
                        else dp[i][j][mask] = min(dp[r][c][mask], dp[r][c][mask^(1<<j)] + 1);
                    }
                }
                if (i==n-1 && j==m-1) ans = min(ans, dp[i][j][mask]);
            }
        }
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }