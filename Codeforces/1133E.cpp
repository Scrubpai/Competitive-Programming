#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n, k, a[5005], lft[5005], dp[5005][5005];
void solve(int tc) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int l = 1, r = 1; r <= n; r++) {
        while (l < r && a[r] - a[l] > 5) l++;
        lft[r] = l;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = max(dp[i-1][j], dp[lft[i]-1][j-1] + i-lft[i]+1);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}