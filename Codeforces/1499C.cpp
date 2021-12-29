#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
#define nl '\n'
int n;
void solve(int tc) {
    cin >> n;
    vector<ll> c(n);
    ll ans=1e18, sumh=0, sumv=0, mnh=1e18, mnv=1e18, curh=-1, curv=-1;
    for (int i=0; i<n; i++) {
        cin >> c[i];
        if (i%2==0) {
            sumh += c[i];
            mnh = min(mnh, c[i]);
            curh = sumh - mnh + 1ll*(n-(i/2))*mnh;
        } else {
            sumv += c[i];
            mnv = min(mnv, c[i]);
            curv = sumv - mnv + 1ll*(n-(i/2))*mnv;
        }
        if (i) ans = min(ans, curh + curv);
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }