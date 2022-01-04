#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e4+5;
#define nl '\n'
struct event { int x, ylo, yhi, v; };
int N, a[MM], cntx, cnty, rx[MM], ry[MM]; vector<event> line1, line2; map<int, int> mpx, mpy;
void solve(int tc) {
    cin >> N;
    for (int i=1, x1, y1, x2, y2; i<=N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        mpy[y1] = mpy[y2] = mpx[x1] = mpx[x2] = 0;
        line1.push_back({x1, y1, y2, 1}); line1.push_back({x2, y1, y2, -1});
        line2.push_back({y1, x1, x2, 1}); line2.push_back({y2, x1, x2, -1});
    }
    for (auto &x : mpx) x.second = ++cntx, rx[cntx] = x.first;
    for (auto &y : mpy) y.second = ++cnty, ry[cnty] = y.first;
    sort(line1.begin(), line1.end(), [](event a, event b) { if (a.x != b.x) return a.x < b.x; else return a.v > b.v; });
    sort(line2.begin(), line2.end(), [](event a, event b) { if (a.x != b.x) return a.x < b.x; else return a.v > b.v; });
    ll ans = 0;
    for (event e : line1) {
        for (int i=mpy[e.ylo]; i<mpy[e.yhi]; i++) {
            a[i] += e.v;
            if ((e.v == 1 && a[i] == 1) || (e.v == -1 && a[i] == 0)) ans += ry[i+1] - ry[i];
        }
    }
    for (event e : line2) {
        for (int i=mpx[e.ylo]; i<mpx[e.yhi]; i++) {
            a[i] += e.v;
            if ((e.v == 1 && a[i] == 1) || (e.v == -1 && a[i] == 0)) ans += rx[i+1] - rx[i];
        }
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }