#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, sum = 0; ll ans = 0; cin >> n; vector<int> a(n), b(n);
        for (int i=0; i<n; i++) { cin >> a[i]; ans += 1ll*(n-2) * a[i] * a[i]; sum += a[i]; }
        for (int i=0; i<n; i++) { cin >> b[i]; ans += 1ll*(n-2) * b[i] * b[i]; sum += b[i]; }
        vector<vector<bool>> dp(2, vector<bool>(sum+2, 0));
        dp[0][0] = 1;
        for (int i=0; i<n; i++) {
            for (int j=sum; j>=a[i]; j--) dp[1][j] = max(dp[1][j], dp[0][j-a[i]]);
            for (int j=sum; j>=b[i]; j--) dp[1][j] = max(dp[1][j], dp[0][j-b[i]]);
            for (int j=0; j<=sum; j++) dp[0][j] = dp[1][j], dp[1][j] = 0;
        }
        ll mn = 1e18;
        for (int i=0; i<=sum; i++) {
            if (dp[0][i] && dp[0][sum-i]) {
                mn = min(mn, 1ll*i*i+(sum-i)*(sum-i));
            }
        }
        ans += mn;
        cout << ans << '\n';
    }
}