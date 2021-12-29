#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
#define nl '\n'
int n, p[MM], dp[MM][2];
void solve(int tc) {
    cin >> n;
    int mx = 1, cnt = 0;
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        dp[i][0] = dp[i][1] = 1;
        if (p[i] > p[i-1]) dp[i][0] += dp[i-1][0];
        else dp[i][1] += dp[i-1][1];
        if (max(dp[i][0], dp[i][1]) > mx) mx = max(dp[i][0], dp[i][1]), cnt = 1;
        else if (max(dp[i][0], dp[i][1]) == mx) cnt++;
    }
    if (cnt != 2) cout << 0;
    else {
        int idx = -1;
        for (int i=1; i<=n; i++) {
            if (max(dp[i][0], dp[i][1]) == mx) {
                idx = i;
                break;
            }
        }
        if (mx % 2 == 0 || p[idx] < p[idx-1] || p[idx] < p[idx+1]) cout << 0;
        else cout << 1;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }