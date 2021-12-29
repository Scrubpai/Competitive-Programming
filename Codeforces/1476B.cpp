#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
int n, k; ll p[105];
void solve(int tc) {
    cin >> n >> k;
    ll ans = 0, sum = 0;
    for (int i=0; i<n; i++) {
        cin >> p[i];
        if (i>0) {
            ll x = (100*p[i] - k*sum + k-1) / k;
            x = max(x, 0ll);
            ans += x; sum += x;
        }
        sum += p[i];
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }