#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5, mod = 1e9+7;
#define nl '\n'
string K; int n, dp[MM][2][2][2];
int fun(int pos, int lmt, int f1, int f0) {
    if (pos == n) {
        if (f1 && f0) return 1;
        return 0;
    }
    if (dp[pos][lmt][f1][f0] != -1) return dp[pos][lmt][f1][f0];
    int &ret = dp[pos][lmt][f1][f0] = 0, mx = lmt ? 9 : K[pos]-'0';
    for (int i=0; i<=mx; i++) {
        if (i == 0 && f0) continue;
        if (i == 0 && f1) ret = (ret + fun(pos+1, i<mx?1:lmt, f1, 1)) % mod;
        else if (i == 1) ret = (ret + fun(pos+1, i<mx?1:lmt, 1, f0)) % mod;
        else ret = (ret + fun(pos+1, i<mx?1:lmt, f1, f0)) % mod;
    }
    return ret;
}
void solve(int tc) {
    cin >> K; n = K.size(); memset(dp, -1, sizeof(dp));
    cout << fun(0, 0, 0, 0) << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }