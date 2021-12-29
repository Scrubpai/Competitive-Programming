#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
struct Rect {
    ll x1, y1, x2, y2;
    ll area() {
        ll len = max(0ll, x2 - x1);
        ll wid = max(0ll, y2 - y1);
        return len * wid;
    }
} a, b, c, d;
ll intersection(Rect m, Rect n) {
    ll xval = max(min(m.x2, n.x2) - max(m.x1, n.x1), 0ll);
    ll yval = max(min(m.y2, n.y2) - max(m.y1, n.y1), 0ll);
    return xval * yval;
}
void solve(int tc) {
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2 >> b.x1 >> b.y1 >> b.x2 >> b.y2 >> c.x1 >> c.y1 >> c.x2 >> c.y2;
    d.x2 = min(b.x2, c.x2); d.x1 = max(b.x1, c.x1); d.y2 = min(b.y2, c.y2); d.y1 = max(b.y1, c.y1);
    if (d.x2 > a.x2) d.x2 = a.x2;
    if (d.x1 < a.x1) d.x1 = a.x1;
    if (d.y2 > a.y2) d.y2 = a.y2;
    if (d.y1 < a.y1) d.y1 = a.y1;
    if (a.area() > intersection(a, b) + intersection(a, c) - d.area()) cout << "YES" << nl;
    else cout << "NO" << nl;
}
int32_t main() {
    //freopen("billboard.in", "r", stdin); freopen("billboard.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}