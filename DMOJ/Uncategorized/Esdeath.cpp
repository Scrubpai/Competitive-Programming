#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))
int N, S, par[5005], ord[5005]; bool vis[5005]; vector<int> adj[5005];
void bfs() {
    queue<int> q; vis[1] = 1; q.push(1); int idx = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ord[++idx] = u;
        for (int v : adj[u]) {
            if (!vis[v]) { q.push(v); par[v] = u; vis[v] = 1; }
        }
    }
}
void dfs(int u, int pa, int D) {
    vis[u] = 1;
    if (!D) return;
    for (int v : adj[u]) {
        if (v != pa) dfs(v, u, D-1);
    }
}
bool chk(int D) {
    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    for (int i=N; i; i--) {
        int v = ord[i];
        if (vis[v]) continue;
        cnt++;
        for (int j=0; j<D; j++) v = par[v];
        dfs(v, 0, D);
    }
    return cnt <= S;
}
void solve(int tc) {
    cin >> N >> S;
    for (int i=1, u, v; i<N; i++) {
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    if (S >= N) { cout << 0 << nl; return; }
    par[1] = 1; bfs();
    int lo = 1, hi = N;
    while (lo < hi) {
        int mid = lo + hi >> 1;
        if (chk(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << hi << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(tc); return 0; }