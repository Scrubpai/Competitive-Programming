#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define INF 0x3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))

//dp[x][y][cnt][rem]: i am at a[x][y], taken cnt numbers from the x-th row, and i have a remainder of rem --> what is the max sum?
int n, m, k, dp[71][71][36][71], v;

void solve(int tc) {

    cin >> n >> m >> k; ms(dp, -INF); dp[0][0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v;
            for (int cnt = 0; cnt <= m / 2; cnt++) {
                for (int rem = 0; rem < k; rem++) {
                    if (dp[i][j][cnt][rem] < 0) continue;
                    if (j == m - 1) {
                        dp[i+1][0][0][rem] = max(dp[i+1][0][0][rem], dp[i][j][cnt][rem]); //do not take it
                        if (cnt < m / 2) dp[i+1][0][0][(rem+v)%k] = max(dp[i+1][0][0][(rem+v)%k], dp[i][j][cnt][rem] + v); //take it
                    } else {
                        dp[i][j+1][cnt][rem] = max(dp[i][j+1][cnt][rem], dp[i][j][cnt][rem]); //do not take it
                        if (cnt < m / 2) dp[i][j+1][cnt+1][(rem+v)%k] = max(dp[i][j+1][cnt+1][(rem+v)%k], dp[i][j][cnt][rem] + v); //take it
                    }
                }
            }
        }
    }
    cout << max(0, dp[n][0][0][0]) << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}