#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MM = 1e5 + 5;
int n, q, a[2*MM]; ll psa[MM];

void solve(int tc) {

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n; i++) psa[i] = psa[i-1] + a[i];
    for (int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;
        if (l > r) swap(l, r);
        ll ans = min(psa[r-1] - psa[l-1], psa[l+n-1] - psa[r-1]);
        cout << ans << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}