#include <bits/stdc++.h>
using namespace std;
const int MM = 4e5+5, MX=4e5;
#define nl '\n'
struct event { int x, y1, y2, id; };
int N, M, ans, bit[MM]; vector<int> vals; vector<event> lines;
void update(int p, int v) { for (; p <= MX; p += p&-p) bit[p]+=v; }
int query(int p) { int ret = 0; for (; p >= 1; p -=p&-p) ret+=bit[p]; return ret; }
void solve(int tc) {
    cin >> N >> M; vals.push_back(-1e9);
    for (int i=1, x1, y1, x2, y2; i<=N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x2<=x1 || y2<=y1) continue;
        lines.push_back({x1, y1, y2, 0}); lines.push_back({x2, y1, y2, 2});
        vals.push_back(y1); vals.push_back(y2);
    }
    for (int i=1, a, b; i<=M; i++) {
        cin >> a >> b;
        vals.push_back(b); lines.push_back({a, b, b,1});
    }
    sort(vals.begin(), vals.end()); vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    sort(lines.begin(), lines.end(), [](event a, event b) { if (a.x != b.x) return a.x < b.x; else return a.id < b.id; });
    for (event e : lines) {
        int y1 = lower_bound(vals.begin(), vals.end(), e.y1) - vals.begin(), y2 = lower_bound(vals.begin(), vals.end(), e.y2) - vals.begin();
        if (e.id == 0) update(y1, 1), update(y2+1, -1);
        else if (e.id == 1) ans += (query(y1) >= 1);
        else if (e.id == 2) update(y1, -1), update(y2+1, 1);
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }