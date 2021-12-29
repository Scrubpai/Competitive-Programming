#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
void solve(int tc) {
    int n; cin >> n;
    vector<int> a(n), b(n), t(n);
    for (int i=0; i<n; i++) cin >> a[i] >> b[i];
    int cur = 0;
    for (int i=0; i<n; i++) {
        cin >> t[i];
        cur += a[i] + t[i];
        if (i) cur -= b[i-1];
        if (i<n-1) {
            cur += (b[i] - a[i] + 1) / 2;
            cur = max(cur, b[i]);
        }
    }
    cout << cur << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }