#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define nl '\n'
#define INF 0x3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))

struct E {
    int u, d, idx;
};

int n, m, k, dis[1005][1005], w[1005], u[1005], v[1005]; vector<E> adj[1005]; vector<pii> ord;

void dijkstra(int st) {
    dis[st][st] = 0; priority_queue<pii, vector<pii>, greater<pii>> pq; pq.push({0, st});
    while (!pq.empty()) {
        pii p = pq.top(); pq.pop();
        if (dis[st][p.second] < p.first) continue;
        for (E nxt : adj[p.second]) {
            int d = nxt.d;
            if (dis[st][nxt.u] > dis[st][p.second] + d) {
                dis[st][nxt.u] = dis[st][p.second] + d;
                pq.push({dis[st][nxt.u], nxt.u});
            }
        }
    }
}

void solve(int tc) {

    cin >> n >> m >> k; ms(dis, INF);
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        adj[u[i]].push_back({v[i], w[i], i});
        adj[v[i]].push_back({u[i], w[i], i});
    }
    for (int i = 1; i <= n; i++) dijkstra(i);
    for (int i = 1, a, b; i <= k; i++) {
        cin >> a >> b;
        ord.push_back({a, b});
    }
    int ans = INF;
    for (int i = 1; i <= m; i++) {
        int tot = 0;
        for (int j = 0; j < k; j++) {
            int a = ord[j].first, b = ord[j].second;
            tot += min({dis[a][b], dis[a][u[i]] + dis[b][v[i]], dis[a][v[i]] + dis[b][u[i]]});
        }
        ans = min(ans, tot);
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}