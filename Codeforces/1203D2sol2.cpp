#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
#define nl '\n'
string s, t; int dp[MM];
//dp[i] = rightmost index of s such that a subsequence of s[dp[i]...n] holds the last i elements of t
void solve(int tc) {
    cin >> s >> t;
    int n = s.size(), m = t.size(), pos = n; s = " " + s; t = " " + t;
    for (int i = m; i >= 1; i--) {
        while (s[pos] != t[i]) pos--;
        dp[m-i+1] = pos;
        pos--;
    }
    dp[0] = n + 1;
    int idx = 1, num = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i > 1 && idx <= m && s[i-1] == t[idx]) idx++, num++;
        //remove a substring of s starting from index i
        int rit = dp[m-num] - 1;
        ans = max(ans, rit - i + 1);
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}