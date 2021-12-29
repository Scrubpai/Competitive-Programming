#include <bits/stdc++.h>
using namespace std;
const int MM = 3e4 + 5;
typedef long long ll;
#define nl '\n'
int n; ll k, c[MM], tmp[MM];
bool check(ll num) {
    ll cnt = 0;
    for (int i = 1; i <= n; i++) tmp[i] = c[i];
    for (int i = 1; i <= n; i++) {
        tmp[i] += tmp[i-1];
        ll add = tmp[i] / num;
        cnt += add;
        if (!add) tmp[i] = c[i];
        else tmp[i] = tmp[i] % num;
    }
    return cnt >= k;
}
void solve(int tc) {
    cin >> n >> k;
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        tot += c[i];
    }
    ll lo = 1, hi = tot / k, ans = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) ans = max(ans, mid), lo = mid + 1;
        else hi = mid - 1;
    }
    cout << ans*k << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}