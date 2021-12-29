#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
#define nl '\n'
int n; ll a[MM], b[MM], c[MM];
void solve(int tc) {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> c[i];
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    ll ans = 0, cur = 0;
    for (int i=2; i<=n; i++) {
        //stop only when a[i] = b[i] (connect to same vertex)
        if (a[i] == b[i]) {
            cur = 2;
        } else {
            ll Min = min(a[i], b[i]), Max = max(a[i], b[i]);
            if (cur == 0) cur = Max - Min;
            else cur = max({Max - Min, cur + (Min - 1) + (c[i-1] - Max)});
            cur += 2;
        }
        ans = max(ans, cur + c[i] - 1);
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }