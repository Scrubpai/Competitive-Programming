#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 2e5 + 5;
#define nl '\n'
int n, m, D, deg, cnt; bool vis[MM], vis2[MM], d[MM]; vector<int> adj[MM]; vector<pii> res;
void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (v == 1) continue;
        if (!vis[v]) {
            dfs(v);
        }
    }
}
void dfs2(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis2[v]) continue;
        if (!vis[v]) {
            res.push_back({u, v});
            dfs2(v);
        }
    }
}
void solve(int tc) {
    cin >> n >> m >> D;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (u == 1 || v == 1) {
            deg++;
            if (u == 1) d[v] = 1;
            else d[u] = 1;
        }
    }
    if (deg < D) { cout << "NO" << nl; return; }
    for (int i = 1; i <= n; i++) {
        if (d[i] && !vis[i]) {
            res.push_back({1, i}); d[i] = 0; vis2[i] = 1;
            cnt++;
            dfs(i);
        }
    }
    if (cnt > D) { cout << "NO" << nl; return; }
    for (int i = 1; i <= n; i++) {
        if (res.size() >= D) break;
        if (d[i]) res.push_back({1, i}), d[i] = 0, vis2[i] = 1;
    }
    memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    for (int i = 1; i <= n; i++) {
        if (vis2[i] && !vis[i]) {
            dfs2(i);
        }
    }
    cout << "YES" << nl;
    for (pii p : res) cout << p.first << " "  << p.second << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}