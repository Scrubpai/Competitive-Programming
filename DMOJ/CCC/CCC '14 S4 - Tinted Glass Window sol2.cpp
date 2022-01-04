#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1005;
#define nl '\n'
int N, T, xl[MM], xr[MM], yt[MM], yb[MM], t[MM], rx[2*MM], ry[2*MM], psa[2*MM][2*MM]; map<int, int> cx, cy;
void solve(int tc) {
    cin >> N >> T;
    for (int i=1; i<=N; i++) {
        cin >> xl[i] >> yt[i] >> xr[i] >> yb[i] >> t[i];
        cx[xl[i]] = 0; cx[xr[i]] = 0; cy[yt[i]] = 0; cy[yb[i]] = 0;
    }
    int cntx = 0, cnty = 0;
    for (auto &x : cx) x.second = ++cntx, rx[cntx] = x.first;
    for (auto &y : cy) y.second = ++cnty, ry[cnty] = y.first;
    for (int i=1; i<=N; i++) {
        int r1 = cy[yt[i]], r2 = cy[yb[i]], c1 = cx[xl[i]], c2 = cx[xr[i]];
        psa[r1][c1] += t[i]; psa[r1][c2] -= t[i]; psa[r2][c1] -= t[i]; psa[r2][c2] += t[i];
    }
    ll ans = 0;
    for (int i=1; i<cnty; i++) {
        for (int j=1; j<cntx; j++) {
            psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
            if (psa[i][j] >= T) ans += 1ll * (ry[i+1] - ry[i]) * (rx[j+1] - rx[j]);
        }
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }