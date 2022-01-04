#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 1e5 + 5, MOD = 10007;
string s; int dp[MM], last[MM];

void solve (int tc) {

    cin >> s;
    for (int i = 1; i <= s.size(); i++) {
       int v = s[i-1] - 'a';
       if (!last[v]) dp[i] = (2 * dp[i-1] + 1) % MOD;
       else dp[i] = (2 * dp[i-1] - dp[last[v]-1]) % MOD;
       last[v] = i;
    }
    cout << dp[s.size()] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}