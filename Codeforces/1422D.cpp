#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int MM = 1e5 + 5;

struct node {
    int x, y, idx;
};
int n, m, sx, sy, fx, fy, x = 1; vector<pll> adj[MM]; node pts[MM]; ll dis[MM];
bool cmp1(node a, node b) {
    return a.x < b.x;
}
bool cmp2(node a, node b) {
    return a.y < b.y;
}

void solve(int tc) {

    cin >> n >> m >> sx >> sy >> fx >> fy;
    adj[1].push_back({m+2, abs(fx - sx) + abs(fy - sy)});
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        pts[i] = {a, b, i+1};
        adj[1].push_back({i+1, min(abs(a - sx), abs(b - sy))});
        adj[i+1].push_back({m+2, abs(a - fx) + abs(b - fy)});
    }
    sort(pts + 1, pts + 1 + m, cmp1);
    for (int i = 1; i < m; i++) {
        adj[pts[i].idx].push_back({pts[i+1].idx, pts[i+1].x - pts[i].x});
        adj[pts[i+1].idx].push_back({pts[i].idx, pts[i+1].x - pts[i].x});
    }
    sort(pts + 1, pts + 1 + m, cmp2);
    for (int i = 1; i < m; i++) {
        adj[pts[i].idx].push_back({pts[i+1].idx, pts[i+1].y - pts[i].y});
        adj[pts[i+1].idx].push_back({pts[i].idx, pts[i+1].y - pts[i].y});
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1}); ms(dis, LL_INF); dis[1] = 0;
    while (!pq.empty()) {
        pll cur = pq.top(); pq.pop();
        if (dis[cur.second] < cur.first) continue;
        for (pll p : adj[cur.second]) {
            if (dis[p.first] > dis[cur.second] + p.second) {
                dis[p.first] = dis[cur.second] + p.second;
                pq.push({dis[p.first], p.first});
            }
        }
    }
    cout << dis[m+2] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}