#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 1e5+5, LOG = 17, MD = 1e6+6;
int N, D, x[MD], y[MD], dep[MM], anc[LOG][MM]; ll d[MM], dp[MD][2]; vector<pi> adj[MM];
void dfs(int u, int pa, ll dis) {
    anc[0][u] = pa; d[u] = dis;
    for (int i=1; i<LOG; i++) anc[i][u] = anc[i-1][anc[i-1][u]];
    for (pi p : adj[u]) {
        int v = p.first, c = p.second;
        if (v == pa) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u, dis + c);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i=LOG-1; i>=0; i--) {
        if (dep[u] - (1<<i) >= dep[v]) u = anc[i][u];
    }
    if (u == v) return u;
    for (int i=LOG-1; i>=0; i--) {
        if (anc[i][u] != anc[i][v]) u = anc[i][u], v = anc[i][v];
    }
    return anc[0][u];
}
ll get(int u, int v) {
    return d[u] + d[v] - 2*d[lca(u, v)];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> D;
    for (int i=1, a, b, c; i<N; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c}); adj[b].push_back({a, c});
    }
    dfs(1, 0, 0);
    x[0] = y[0] = 1;
    for (int i=1; i<=D; i++) {
        cin >> x[i] >> y[i];
        dp[i][0] = min(dp[i-1][0] + get(x[i-1], y[i]), dp[i-1][1] + get(y[i-1], y[i])) + get(x[i], y[i]);
        dp[i][1] = min(dp[i-1][0] + get(x[i-1], x[i]), dp[i-1][1] + get(y[i-1], x[i])) + get(x[i], y[i]);
    }
    printf("%lld\n", min(dp[D][0], dp[D][1]));
}