#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int n, m, dp[3005][3], ans; char a[3005][3005];

void calc(int r, int c) {
    int dia = 0;
    while (r >= 1 && c <= m) {
        dia++;
        dp[dia][0] = max({dp[dia-1][0], dp[dia-1][1], dp[dia-1][2]}); dp[dia][1] = 0; dp[dia][2] = 0;
        if (a[r][c-1] == 'R' && a[r][c] == 'G' && a[r][c+1] == 'W') dp[dia][1] = max(dp[dia-1][0], dp[dia-1][1]) + 1;
        if (a[r-1][c] == 'R' && a[r][c] == 'G' && a[r+1][c] == 'W') dp[dia][2] = max(dp[dia-1][0], dp[dia-1][2]) + 1;
        r--; c++;
    }
    ans += max({dp[dia][0], dp[dia][1], dp[dia][2]});
}

void solve(int tc) {

    cin >> n >> m;
    //0: not used, 1: used horizontally, 2: used vertically
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) calc(i, 1);
    for (int j = 2; j <= m; j++) calc(n, j);
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}