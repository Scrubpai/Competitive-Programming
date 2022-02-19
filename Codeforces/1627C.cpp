#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 1e5+5; vector<pi> adj[MM]; vector<int> ord;
void dfs(int u, int pa) {
    for (pi p : adj[u]) {
        int v = p.first, id = p.second;
        if (v == pa) continue;
        ord.push_back(id);
        dfs(v, u);
    }
}
void solve() {
    int n; cin >> n; vector<int> ans(n+1, 0), deg(n+1, 0); ord.clear();
    for (int i=1; i<=n; i++) adj[i].clear();
    for (int i=1, u, v; i<n; i++) {
        cin >> u >> v; deg[u]++; deg[v]++;
        adj[u].push_back({v, i}); adj[v].push_back({u, i});
    }
    for (int i=1; i<=n; i++) {
        if (deg[i] >= 3) { cout << -1 << '\n'; return; }
    }
    for (int i=1; i<=n; i++) {
        if (deg[i] == 1) {
            dfs(i, 0); break;
        }
    }
    for (int i=0; i<(int)ord.size(); i++) {
        if (i&1) ans[ord[i]] = 2;
        else ans[ord[i]] = 5;
    }
    for (int i=1; i<n; i++) cout << ans[i] << ' ';
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; for (int i=0; i<t; i++) solve();
}