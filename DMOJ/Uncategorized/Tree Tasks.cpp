#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
typedef pair<int, int> pi;
#define f first
#define s second
int N, dis[MM], pre[MM], src, maxd, rad=1e9; vector<pi> adj[MM];
void dfs(int u, int pa, int d) {
    dis[u] = d; pre[u] = pa;
    if (d > maxd) maxd = d, src = u;
    for (pi p : adj[u]) {
        if (p.f == pa) continue;
        dfs(p.f, u, d+p.s);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1, u, v, w; i<N; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }
    dfs(1, 0, 0); dfs(src, 0, 0);
    for (int i=src; i; i=pre[i]) rad = min(rad, max(dis[i], maxd-dis[i]));
    printf("%d\n%d\n", maxd, rad);
}