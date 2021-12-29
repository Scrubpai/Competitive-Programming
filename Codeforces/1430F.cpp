#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))

//dp[i] = minimum # of bullets used assuming we completed i (0 <= i < n) waves, and now we are standing at l[i] with a full magazine
ll n, k, l[2005], r[2005], a[2005], dp[2005], ans = LL_INF;

void solve(int tc) {

    cin >> n >> k; ms(dp, LL_INF); dp[0] = 0;
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i] >> a[i];
    for (int i = 0; i < n; i++) {
        ll rem = k, tot = dp[i];
        for (int j = i; j < n; j++) { //no wasted bullets
            //rem ... rem + k ... rem + 2k >= a[j]. rem + x * k >= a[j]
            ll x = max(0LL, (a[j] - rem + k - 1) / k); //# of reloads
            if (x > r[j] - l[j]) break;
            rem = rem + x * k - a[j]; tot += a[j];
            if (j < n - 1) {
                //if two waves are consecutive and u are shooting the first wave at r[i], you never want to reload at l[i+1]
                if (l[j] + x < l[j+1]) dp[j+1] = min(dp[j+1], tot + rem);
            } else {
                ans = min(ans, tot);
            }
        }
    }
    if (ans == LL_INF) ans = -1;
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}