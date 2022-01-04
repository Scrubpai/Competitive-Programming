#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pt;
#define x first
#define y second
#define nl '\n'
int n, ans; pt r, j;
bool rectCheck(pt p1, pt p2, pt q1, pt q2) {
    int lft = min(p1.x, p2.x), rit = max(p1.x, p2.x), bot = min(p1.y, p2.y), top = max(p1.y, p2.y);
    return (rit >= min(q1.x, q2.x) && max(q1.x, q2.x) >= lft && top >= min(q1.y, q2.y) && max(q1.y, q2.y) >= bot);
}
int c(pt a, pt b, pt c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
bool intersect(pt p1, pt p2, pt q1, pt q2) {
    if (rectCheck(p1, p2, q1, q2) && 1ll * c(p1, p2, q1) * c(p1, p2, q2) <= 0 && 1ll * c(q1, q2, p1) * c(q1, q2, p2) <= 0) return 1;
    return 0;
}
void solve(int tc) {
    cin >> r.x >> r.y >> j.x >> j.y >> n;
    for (int t=1; t<=n; t++) {
        vector<pt> vec; int k = 0;
        cin >> k;
        for (int i=0, x, y; i<k; i++) {
            cin >> x >> y;
            vec.emplace_back(make_pair(x, y));
        }
        for (int i=0; i<k; i++) {
            if (intersect(r, j, vec[i], vec[(i+1)%k])) { ans++; break; }
        }
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }