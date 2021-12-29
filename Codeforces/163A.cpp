#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define nl '\n'
string s, t; int dp[5005][5005];
void solve(int tc) {
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s; t = " " + t;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i][j-1];
            if (s[i] == t[j]) dp[i][j] = (dp[i][j] + dp[i-1][j-1] + 1) % mod;
        }
        ans = (ans + dp[i][m]) % mod;
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1;// cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}