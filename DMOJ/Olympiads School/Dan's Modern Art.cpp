#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+5;
#define nl '\n'
int n, x[MM], y[MM], w[MM], h[MM];
void solve(int tc) {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> x[i] >> y[i] >> w[i] >> h[i];
    int p, q; cin >> p >> q;
    int ans = -1;
    for (int i=1; i<=n; i++) {
        if (p >= x[i] && p <= x[i] + w[i] && q >= y[i] && q <= y[i] + h[i]) ans = i;
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }