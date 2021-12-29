#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
int n;
void solve(int tc) {
    cin >> n;
    vector<ll> a(n);
    ll mx = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    ll c = a[1] - a[0], m = 0;
    for (int i=2; i<n; i++) {
        if (a[i-1] + c != a[i]) m = abs(a[i-1] + c - a[i]);
    }
    if (!m) { cout << 0 << nl; return; }
    if (m <= mx) { cout << -1 << nl; return; }
    for (int i=1; i<n; i++) {
        if (a[i] != (a[i-1] + c + m) % m) {
            cout << -1 << nl;
            return;
        }
    }
    cout << m << " " << (c+m)%m << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }