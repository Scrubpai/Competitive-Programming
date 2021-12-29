#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const ll INF = 1e18;
ll n, k, l1, r1, l2, r2;

void solve(int tc) {

    cin >> n >> k >> l1 >> r1 >> l2 >> r2;
    ll I = n * (max(0ll, min(r1, r2) - max(l1, l2)));
    if (I >= k) { cout << 0 << nl; return; }
    if (I > 0) {
        ll tot = n * (max(r1, r2) - min(l1, l2)), rem = 0;
        if (tot < k) rem += k - tot;
        if (rem == 0) cout << k - I << nl;
        else cout << k - I + rem << nl;
    } else {
        ll ans = INF;
        for (int cnt = 1; cnt <= n; cnt++) {
            ll v = cnt * (max(l1, l2) - min(r1, r2)), intersect = cnt * (max(r1, r2) - min(l1, l2));
            if (intersect >= k) {
                ans = min(ans, v + k);
            } else {
                ll rem = k - intersect;
                ans = min(ans, v + intersect + 2 * rem);
            }
        }
        cout << ans << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}