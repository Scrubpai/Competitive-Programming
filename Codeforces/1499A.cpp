#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n, k1, k2, w, b;
void solve(int tc) {
    cin >> n >> k1 >> k2 >> w >> b;
    int mxw = min(k1, k2) + (max(k1, k2) - min(k1, k2))/2, mxb = n - max(k1, k2) + (max(k1, k2) - min(k1, k2))/2;
    if (mxw >= w && mxb >= b) cout << "YES" << nl;
    else cout << "NO" << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }