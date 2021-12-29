#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int A, B, W;
void solve(int tc) {
    cin >> A >> B >> W; W *= 1000;
    int mn = 1e9, mx = 0;
    for (int i=1; i<=W; i++) {
        if (A*i<=W && B*i>=W) mn = min(mn, i), mx = max(mx, i);
    }
    if (mn == 1e9) cout << "UNSATISFIABLE" << nl;
    else cout << mn << " " << mx << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }