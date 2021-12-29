#include <bits/stdc++.h>
using namespace std;
const int MM = (1<<10)+5, mod = 1e9+7;
#define nl '\n'
int N, a[11], dp[MM][MM][2][2], idx[11]; string K;
int fun(int pos, int mask, int f1, int f0) {
    if (pos == (int)K.size()) {
        if (mask == (1<<N)-1) return 1;
        return 0;
    }
    if (dp[pos][mask][f1][f0] != -1) return dp[pos][mask][f1][f0];
    int &ret = dp[pos][mask][f1][f0] = 0, mx = f1?9:(K[pos]-'0');
    for (int i=0; i<=mx; i++) {
        ret = (ret + fun(pos+1, mask | ((idx[i]==-1||(!f0&&i==0))?0:(1<<idx[i])), i<mx?1:f1, i==0?f0:1)) % mod;
    }
    return ret;
}
void solve(int tc) {
    cin >> N; memset(idx, -1, sizeof(idx)); for (int i=0; i<N; i++) { cin >> a[i]; idx[a[i]] = i; } cin >> K; memset(dp, -1, sizeof(dp));
    cout << fun(0, 0, 0, 0) + (N==1&&a[0]==0)?1:0 << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }