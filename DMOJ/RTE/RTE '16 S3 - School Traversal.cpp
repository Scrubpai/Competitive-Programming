#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second
const int MM = 6005, LOG = 13;
int N, Q, anc[LOG][MM], dep[MM]; ll d[MM]; vector<pii> adj[MM];
void dfs(int u, int pa, ll dis) {
    anc[0][u] = pa; d[u] = dis;
    for (int i=1; i<LOG; i++) anc[i][u] = anc[i-1][anc[i-1][u]];
    for (pii p : adj[u]) {
        if (p.f == pa) continue;
        dep[p.f] = dep[u] + 1;
        dfs(p.f, u, dis+p.s);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i=LOG-1; i>=0; i--) {
        if (dep[u] - (1<<i) >= dep[v]) u = anc[i][u];
    }
    if (u == v) return u;
    for (int i=LOG-1; i>=0; i--) {
        if (anc[i][u] != anc[i][v]) {
            u = anc[i][u]; v = anc[i][v];
        }
    }
    return anc[0][u];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1, a, b, w; i<N; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w}); adj[b].push_back({a, w});
    }
    dfs(0, 0, 0);
    cin >> Q;
    for (int i=0, u, v; i<Q; i++) {
        cin >> u >> v;
        printf("%lld\n", d[u] + d[v] - 2*d[lca(u, v)]);
    }
    return 0;
}