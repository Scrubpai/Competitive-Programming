#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define INF 0x3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
//dp[i][j][k]: first i rows, remainder is j when divided by K, k#s have been chosen
int n, m, k, a[71][71], dp[71][71], tmp[71][71]; bool vis[71][71];

void solve(int tc) {

    cin >> n >> m >> k; ms(dp, -INF); dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
        sort(a[i] + 1, a[i] + 1 + m, greater<int>());
        ms(tmp, -INF); tmp[0][0] = 0;
        for (int j = 1; j <= m; j++) {
            ms(vis, 0);
            for (int r = 0; r < k; r++) {
                int nxt = (r + a[i][j]) % k;
                for (int cnt = m / 2 - 1; cnt >= 0; cnt--) {
                    if (tmp[r][cnt] >= 0 && tmp[r][cnt] + a[i][j] > tmp[nxt][cnt+1] && !vis[r][cnt]) {
                        tmp[nxt][cnt+1] = tmp[r][cnt] + a[i][j];
                        vis[nxt][cnt+1] = 1;
                    }
                }
            }
        }
        for (int r = 0; r < k; r++) {
            for (int cnt = 1; cnt <= (m / 2); cnt++) {
                tmp[r][cnt] = max(tmp[r][cnt], tmp[r][cnt-1]);
            }
        }
        for (int j = 0; j < k; j++) {
            for (int r = 0; r < k; r++) {
                int nxt = (j + r) % k;
                dp[i][nxt] = max(dp[i][nxt], dp[i-1][j] + tmp[r][m/2]);
            }
        }
    }
    cout << max(0, dp[n][0]) << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}