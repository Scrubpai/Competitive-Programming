#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
typedef long long ll;
#define nl '\n'
int n, a[MM], sum, tmp; vector<int> fac;
void solve(int tc) {
    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> a[i]; sum += a[i]; }
    if (sum == 1) { cout << -1 << nl; return; }
    tmp = sum;
    for (int i = 2; i <= sum; i++) {
        if (tmp % i == 0) {
            fac.push_back(i);
            while (tmp % i == 0) tmp /= i;
        }
    }
    ll ans = 1e18;
    for (int f : fac) {
        vector<int> pos;
        ll tot = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i]) pos.push_back(i);
            if (pos.size() == f) {
                if (f == 2) tot += pos[1] - pos[0];
                else {
                    int median = pos[pos.size()/2];
                    for (int p : pos) tot += abs(p - median);
                }
                pos.clear();
            }
        }
        ans = min(ans, tot);
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}