#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
#define f first
#define s second
const int MM = 2e4+5;
int n, m, k, q, d1[201][MM], d2[201][MM]; vector<pi> adj1[MM], adj2[MM];
void dijkstra(int st, int d[], vector<pi> adj[]) {
    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.push({0, st}); d[st] = 0;
    while (!pq.empty()) {
        int dis = pq.top().f, u = pq.top().s; pq.pop();
        if (dis > d[u]) continue;
        for (pi p : adj[u]) {
            int v = p.f, c = p.s;
            if (d[v] > d[u] + c) {
                d[v] = d[u] + c;
                pq.push({d[v], v});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> k >> q; memset(d1, 0x3f, sizeof(d1)); memset(d2, 0x3f, sizeof(d2));
    for (int i=1, u, v, d; i<=m; i++) {
        cin >> u >> v >> d;
        adj1[u].push_back({v, d});
        adj2[v].push_back({u, d});
    }
    for (int i=1, x; i<=k; i++) {
        cin >> x;
        dijkstra(x, d1[i], adj1);
        dijkstra(x, d2[i], adj2);
    }
    ll ans = 0, cnt = 0;
    for (int i=1, a, b; i<=q; i++) {
        cin >> a >> b;
        int v = 1e9;
        for (int j=1; j<=k; j++) v = min(v, d2[j][a] + d1[j][b]);
        if (v!=1e9) cnt++, ans += v;
    }
    printf("%d\n%lld\n", cnt, ans);
}