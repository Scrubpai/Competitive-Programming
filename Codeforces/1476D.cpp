#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5+5;
#define nl '\n'
int N, dp[MM][2], ans[MM]; char a[MM];
void solve(int tc) {
    cin >> N;
    for (int i=1; i<=N; i++) cin >> a[i];
    memset(dp, 0, sizeof(dp));
    memset(ans, 0, sizeof(ans));
    for (int i=N; i>=1; i--) {
        if (a[i] == 'R') {
            dp[i][1] = dp[i+2][1] + 1;
            if (dp[i][1] > dp[i+1][0]) {
                ans[i-1] = 2*dp[i+1][0] + 1;
            } else if (dp[i][1] <= dp[i+1][0]) {
                ans[i-1] = 2*dp[i][1];
            }
        } else {
            dp[i][0] += dp[i+2][0] + 1;
        }
    }
    memset(dp, 0, sizeof(dp));
    if (a[1] == 'L') dp[1][0] = 1, ans[1]++;
    else dp[1][1] = 1;
    for (int i=2; i<= N; i++) {
        if (a[i] == 'L') {
            dp[i][0] = dp[i-2][0] + 1;;
            if (dp[i][0] > dp[i-1][1]) {
                ans[i] += 2*dp[i-1][1] + 1;
            } else {
                ans[i] += 2*dp[i][0];
            }
        } else {
            dp[i][1] = dp[i-2][1] + 1;
        }
    }
    for (int i=0; i<=N; i++) cout << ans[i]+1 << ' ';
    cout << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }