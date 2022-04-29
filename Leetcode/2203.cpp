typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, int> pl;
const int MM = 1e5+5;
class Solution {
public:
    vector<pi> fwd[MM], rev[MM]; ll dist[3][MM];
    void dijkstra(int n, int src, ll dis[], vector<pi> adj[MM]) {
        priority_queue<pl, vector<pl>, greater<pl>> pq;
        for (int i=0; i<n; i++) dis[i] = 1e18; dis[src] = 0; pq.push({0, src});
        while (!pq.empty()) {
            ll d = pq.top().first; int u = pq.top().second; pq.pop();
            if (d > dis[u]) continue;
            for (auto &[v, l]: adj[u]) {
                if (dis[v] > dis[u] + l) {
                    dis[v] = dis[u] + l;
                    pq.push({dis[v], v});
                }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        for (int i=0; i<(int)edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            fwd[u].push_back({v, w});
            rev[v].push_back({u, w});
        }
        dijkstra(n, src1, dist[0], fwd);
        dijkstra(n, src2, dist[1], fwd);
        dijkstra(n, dest, dist[2], rev);
        ll ans = 1e18;
        for (int i=0; i<n; i++) {
            if (dist[0][i] == 1e18 || dist[1][i] == 1e18 || dist[2][i] == 1e18) continue;
            ans = min(ans, dist[2][i] + dist[0][i] + dist[1][i]);
        }
        if (ans == 1e18) return -1;
        return ans;
    }
};