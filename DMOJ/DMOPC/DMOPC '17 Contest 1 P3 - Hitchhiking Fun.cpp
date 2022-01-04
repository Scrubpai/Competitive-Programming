#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define nl '\n'
#define INF 0x3f3f3f3f
const int MM = 1e5 + 5;
int N, M, dis[MM], roads[MM]; vector<pii> adj[MM];
void solve(int tc) {
    cin >> N >> M;
    for (int i = 1, a, b, t; i <= M; i++) {
        cin >> a >> b >> t;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }
    memset(dis, INF, sizeof(dis)); dis[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq; pq.push({0, 1});
    while (!pq.empty()) {
        int u = pq.top().second, d = pq.top().first; pq.pop();
        if (d > dis[u]) continue;
        for (pii p : adj[u]) {
            int v = p.first, w = p.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w; roads[v] = roads[u] + 1;
                pq.push({dis[v], v});
            } else if (dis[v] == dis[u] + w && roads[v] > roads[u] + 1) {
                roads[v] = roads[u] + 1;
                pq.push({dis[v], v});
            }
        }
    }
    if (dis[N] == INF) cout << -1 << nl;
    else cout << dis[N] << " " << roads[N] << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}