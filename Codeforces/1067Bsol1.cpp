#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
#define nl '\n'
int n, k, maxd, far, pre[MM], dep[MM]; vector<int> adj[MM], ord;
void dfs(int u, int pa, int d) {
    if (d > maxd) maxd = d, far = u;
    pre[u] = pa;
    for (int v : adj[u]) {
        if (v != pa) {
            dep[v] = dep[u] + 1;
            dfs(v, u, d+1);
        }
    }
}
void solve(int tc) {
    cin >> n >> k;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    if (k > 1e5) { cout << "No" << nl; return; }
    dfs(1, 0, 0); maxd = 0; dfs(far, 0, 0);
    if (maxd != 2 * k) { cout << "No" << nl; return; }
    for (int i = far; i != 0; i = pre[i]) ord.push_back(i);
    int center = ord[k];
    memset(dep, 0, sizeof(dep));
    dfs(center, 0, 0);
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            if (dep[i] != k) {
                cout << "No" << nl;
                return;
            }
        } else {
            if (i == center && adj[i].size() < 3) {
                cout << "No" << nl;
                return;
            } else if (i != center && adj[i].size() < 4) {
                cout << "No" << nl;
                return;
            }
        }
    }
    cout << "Yes" << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}