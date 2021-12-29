#define ms(x, y) memset(x, y, sizeof(x))
#define INF 0x3f3f3f3f // for int
typedef pair<int, int> pii;
class Solution {
public:
    vector<pii> adj[105]; int dis[105]; priority_queue<pii, vector<pii>, greater<pii>> pq;
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0], v = times[i][1], w = times[i][2];
            adj[u].push_back({v, w});
        }
        ms(dis, INF); dis[K] = 0; pq.push({0, K});
        while (!pq.empty()) {
            int u = pq.top().second, d = pq.top().first; pq.pop();
            if (dis[u] < d) continue;
            for (pii p : adj[u]) {
                int v = p.first; d = dis[u] + p.second;
                if (dis[v] > d) {
                    dis[v] = d; pq.push({dis[v], v});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= N; i++) ans = max(ans, dis[i]);
        if (ans == INF) return -1;
        return ans;
    }
}; 