#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define INF 0x3f3f3f3f
int n, a[305][305], dp[2][305][305];
void solve(int tc) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    memset(dp, -INF, sizeof(dp));
    dp[0][1][1] = a[1][1];
    for (int i = 1; i <= n + n - 2; i++) {
        //total number of steps from (1,1) to (n,n) is n+n-2
        int sum = i & 1;
        for (int r1 = 1; r1 <= min(n, i + 1); r1++) {
            for (int r2 = 1; r2 <= min(n, i + 1); r2++) {
                dp[sum][r1][r2] = max({dp[sum^1][r1][r2], dp[sum^1][r1-1][r2], dp[sum^1][r1][r2-1], dp[sum^1][r1-1][r2-1]});
                if (r1 == r2) dp[sum][r1][r2] += a[r1][i-r1+2];
                else dp[sum][r1][r2] += a[r1][i-r1+2] + a[r2][i-r2+2];
            }
        }
    }
    cout << dp[0][n][n] << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}