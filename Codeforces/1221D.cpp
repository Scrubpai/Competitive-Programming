#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3e5 + 5;
#define nl '\n'
int n; ll a[MM], b[MM], dp[MM][3];
void solve(int tc) {
    cin >> n; 
    //dp[i][j]: minimum rubies to make the first i fences great while increasing the ith fence j times
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        dp[i][0] = dp[i][1] = dp[i][2] = 1e18;
        if (i == 1) { dp[1][0] = 0; dp[1][1] = b[1]; dp[1][2] = 2*b[1]; continue; }
        if (a[i] != a[i-1]) dp[i][0] = min(dp[i][0], dp[i-1][0]);
        if (a[i] != a[i-1] + 1) dp[i][0] = min(dp[i][0], dp[i-1][1]);
        if (a[i] != a[i-1] + 2) dp[i][0] = min(dp[i][0], dp[i-1][2]);
        if (a[i] + 1 != a[i-1]) dp[i][1] = min(dp[i][1], dp[i-1][0] + b[i]);
        if (a[i] + 1 != a[i-1] + 1) dp[i][1] = min(dp[i][1], dp[i-1][1] + b[i]);
        if (a[i] + 1 != a[i-1] + 2) dp[i][1] = min(dp[i][1], dp[i-1][2] + b[i]);
        if (a[i] + 2 != a[i-1]) dp[i][2] = min(dp[i][2], dp[i-1][0] + 2*b[i]);
        if (a[i] + 2 != a[i-1] + 1) dp[i][2] = min(dp[i][2], dp[i-1][1] + 2*b[i]);
        if (a[i] + 2 != a[i-1] + 2) dp[i][2] = min(dp[i][2], dp[i-1][2] + 2*b[i]);
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}