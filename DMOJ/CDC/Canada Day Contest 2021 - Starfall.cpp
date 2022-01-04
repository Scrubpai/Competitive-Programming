#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 4e5+5;
#define nl '\n'
struct event { ll t, l, r; };
ll n, k, t[MM], x[MM], y[MM], lx, rx, ly, ry;
bool check(vector<event> &v, ll s) {
    ll m = v.size(), lft = v[0].r, rit = v[0].l + s;
    for (int i=1; i<m; i++) {
        ll l = v[i].l, r = v[i].r, mind = 1e9;
        if (lft >= r && lft <= l+s) mind = 0;
        else mind = min(abs(lft-l-s), abs(lft-r));
        if (rit >= r && rit <= l+s) mind = 0;
        else mind = min({mind, abs(rit-l-s), abs(rit-r)});
        if (l+s<=rit && r>=lft) mind = 0;
        if (mind > (v[i].t - v[i-1].t) * k) return 0;

        lft = min(max(r, lft - (v[i].t - v[i-1].t) * k), l+s);
        rit = max(min(l+s, rit + (v[i].t - v[i-1].t) * k), r);
    }
    return 1;
}
void solve(int tc) {
    cin >> n >> k >> t[1] >> x[1] >> y[1];
    lx = rx = x[1]; ly = ry = y[1];
    vector<event> vx, vy;
    ll lowx = 0, hix = 1e9, lowy = 0, hiy = 1e9;
    for (int i=2; i<=n; i++) {
        cin >> t[i] >> x[i] >> y[i];
        if (t[i] == t[i-1]) lx = min(lx, x[i]), rx = max(rx, x[i]), ly = min(ly, y[i]), ry = max(ry, y[i]);
        else {
            lowx = max(lowx, rx - lx);
            lowy = max(lowy, ry - ly);
            vx.push_back({t[i-1], lx, rx}); vy.push_back({t[i-1], ly, ry});
            lx = rx = x[i]; ly = ry = y[i];
        }
    }
    lowx = max(lowx, rx - lx); lowy = max(lowy, ry - ly); vx.push_back({t[n], lx, rx}); vy.push_back({t[n], ly, ry});
    while (lowx < hix) {
        ll mid = (lowx + hix) / 2;
        if (check(vx, mid)) hix = mid;
        else lowx = mid+1;
    }
    while (lowy < hiy) {
        ll mid = (lowy + hiy) / 2;
        if (check(vy, mid)) hiy = mid;
        else lowy = mid+1;
    }
    cout << max(lowx, lowy) << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }