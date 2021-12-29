#include <bits/stdc++.h>
using namespace std;
string s, t; int dp[3005][3005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size(); s = " " + s; t = " " + t;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (s[i] == t[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    string ans = "";
    for (int i=n, j=m; i&&j; ) {
        if (dp[i][j] == dp[i-1][j]) i--;
        else if (dp[i][j] == dp[i][j-1]) j--;
        else ans += s[i], i--, j--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}