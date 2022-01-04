#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1005;
#define nl '\n'
struct event { int x, ylo, yhi, v; };
int N, T, v[2*MM], ry[2*MM]; vector<event> line; map<int, int> cy;
void solve(int tc) {
    cin >> N >> T;
    for (int i=1, xl, xr, yt, yb, t; i<=N; i++) {
        cin >> xl >> yt >> xr >> yb >> t;
        cy[yt] = cy[yb] = 0;
        line.push_back({xl, yt, yb, t}); line.push_back({xr, yt, yb, -t});
    }
    int cnt = 0;
    for (auto &y : cy) y.second = ++cnt, ry[cnt] = y.first;
    sort(line.begin(), line.end(), [](event a, event b) { return a.x < b.x; });
    ll ans = 0;
    for (int i=0; i<line.size(); i++) {
        event cur = line[i];
        if (i>0) {
            for (int j=1; j<cnt; j++) {
                if (v[j]<T) continue;
                ans += 1ll * (ry[j+1] - ry[j]) * (line[i].x - line[i-1].x);
            }
        }
        for (int j=cy[cur.ylo]; j<cy[cur.yhi]; j++) {
            v[j] += cur.v;
        }
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }