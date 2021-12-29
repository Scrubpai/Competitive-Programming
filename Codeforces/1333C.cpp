#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5 + 5;
#define nl '\n'
int n, last[MM]; ll a[MM], psa[MM]; map<ll, int> mp;
void solve(int tc) {
    cin >> n;
    ll ans = 0;
    mp[0] = 1;
    for (int r = 1; r <= n; r++) {
        cin >> a[r];
        psa[r] = psa[r-1] + a[r];
        if (a[r] == 0) { last[r] = r; continue; }
        last[r] = last[r-1];
        if (mp.count(psa[r])) last[r] = max(last[r], mp[psa[r]]);
        ans += r - last[r];
        mp[psa[r]] = r + 1;
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}