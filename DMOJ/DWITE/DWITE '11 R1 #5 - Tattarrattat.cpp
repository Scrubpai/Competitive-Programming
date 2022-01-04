#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))

string s; int dp[300][300];

void solve(int tc) {

    cin >> s; int n = s.size(); ms(dp, 0);
    string s2 = s; reverse(s2.begin(), s2.end()); s = " " + s; s2 = " " + s2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i] == s2[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout << dp[n][n] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 5; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}