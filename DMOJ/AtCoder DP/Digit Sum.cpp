#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+5, mod = 1e9+7;
#define nl '\n'
string K; int D, n, dp[MM][105][2];
int fun(int pos, int sum, int lmt) {
    if (pos == n) {
        if (sum == 0) return 1;
        return 0;
    }
    if (dp[pos][sum][lmt] != -1) return dp[pos][sum][lmt];
    int &ret = dp[pos][sum][lmt] = 0, mx = lmt?9:(K[pos]-'0');
    for (int i=0; i<=mx; i++) {
        ret = (ret + fun(pos+1, (sum+i)%D, i<mx?1:lmt)) % mod;
    }
    return ret;
}
void solve(int tc) {
    cin >> K >> D; n = K.size(); memset(dp, -1, sizeof(dp));
    cout << fun(0, 0, 0)-1 << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }