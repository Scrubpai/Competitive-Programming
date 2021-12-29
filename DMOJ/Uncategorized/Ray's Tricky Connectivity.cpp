#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 4e5+5;
int N, M, Q, d[MM]; vector<pi> adj[MM];
void dijkstra() {
    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.push({0, 1}); d[1] = 0;
    while (!pq.empty()) {
        int e = pq.top().first, u = pq.top().second; pq.pop();
        if (e > d[u]) continue;
        for (pi p : adj[u]) {
            int v = p.first, e2 = p.second;
            if (d[v] > max(e, e2)) {
                d[v] = max(e, e2);
                pq.push({d[v], v});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M >> Q; vector<pi> queries;
    for (int i=1, x, y; i<=M; i++) {
        cin >> x >> y;
        adj[x].push_back({y, 0});
    }
    for (int i=1, x, y; i<=Q; i++) {
        char op; cin >> op;
        if (op == '?') {
            cin >> x;
            queries.push_back({x, i});
        } else {
            cin >> x >> y;
            adj[x].push_back({y, i});
        }
    }
    memset(d, 0x3f, sizeof(d)); dijkstra();
    for (pi p : queries) {
        if (d[p.first] <= p.second) cout << "YES\n";
        else cout << "NO\n";
    }
}