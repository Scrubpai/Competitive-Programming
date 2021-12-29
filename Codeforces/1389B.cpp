#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MM = 2e5 + 5;
ll n, k, z, a[MM], psa[MM];

void solve(int tc) {

    cin >> n >> k >> z; ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psa[i] = psa[i-1] + a[i];
    }
    for (int i = 0; i <= z; i++) {
        ll rit = k - i, lft = i;
        for (int j = 2; j <= n; j++) {
            ll r = rit - (j - 1), v = psa[j] - psa[1];
            if (r < 0 || r + 1 < lft) break;
            if (r + 1 == lft) v += (a[j-1] * lft) + (a[j] * r);
            else {
                v += (a[j-1] * lft) + (a[j] * lft);
                r -= lft;
                if (j + r > n) break;
                v += (psa[j+r] - psa[j]);
            }
            ans = max(ans, v);
        }
    }
    cout << ans + a[1] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}