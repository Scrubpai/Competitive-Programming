#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 2e5+5;
#define nl '\n'
struct edge { ll u, v, w, id; };
int n, m, dsu[MM], xr, cnt, dp[MM]; set<int> adj[MM], unvis; vector<pii> g[MM]; vector<edge> mst;
int fd(int u) {
    if (dsu[u] != u) dsu[u] = fd(dsu[u]);
    return dsu[u];
}
void dfs(int x) {
    unvis.erase(x);
    int cur = -1;
    while (true) {
        auto it = unvis.upper_bound(cur);
        if (it == unvis.end()) break;
        cur = *it;
        if (adj[x].count(cur)) continue;
        dsu[fd(x)] = fd(cur), cnt++;
        g[x].emplace_back(make_pair(cur, 0));
        g[cur].emplace_back(make_pair(x, 0));
        dfs(cur);
    }
}
void dfs2(int u, int pa) {
    for (pii p : g[u]) {
        if (p.first == pa) continue;
        if (p.second == 0) dp[p.first] = p.first;
        else dp[p.first] = dp[u];
        dfs2(p.first, u);
    }
}
void solve(int tc) {
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].insert(v); adj[v].insert(u);
        mst.push_back({u, v, w, i});
        xr ^= w;
    }
    for (int i=1; i<=n; i++) unvis.insert(i), dsu[i] = i;
    for (int i=1; i<=n; i++) {
        if (unvis.count(i)) {
            dfs(i);
        }
    }
    sort(mst.begin(), mst.end(), [](edge a, edge b) { return a.w < b.w; });
    ll ans = 0, mn = 2e9;
    set<int> used;
    for (edge e : mst) {
        int u = e.u, v = e.v, w = e.w, fu = fd(u), fv = fd(v);
        if (fu != fv) used.insert(e.id), dsu[fu] = fv, ans += w, g[u].emplace_back(make_pair(v, w)), g[v].emplace_back(make_pair(u, w));
    }
    dfs2(1, 0);
    for (edge e : mst) {
        if (used.count(e.id)) continue;
        if (dp[e.u] != dp[e.v]) mn = min(mn, 1ll*e.w);
    }
    if ((1ll * n * (n - 1) / 2) - m > cnt) cout << ans << nl;
    else cout << ans + min(1ll*xr, mn) << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }