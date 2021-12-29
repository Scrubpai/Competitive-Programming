#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
#define nl '\n'
int n, k, deg[MM], hedge[MM]; vector<int> adj[MM]; bool vis[MM];
void solve(int tc) {
    cin >> n >> k;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        deg[u]++; deg[v]++;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) q.push(i), vis[i] = 1, hedge[i] = k;
    }
    bool flag = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        deg[cur]--; //deleted
        for (int v : adj[cur]) {
            if (deg[v]) {
                if (!vis[v]) {
                    hedge[v] = hedge[cur] - 1;
                    if (hedge[v] && deg[v] < 4) { cout << "No" << nl; return; }
                    else if (!hedge[v] && deg[v] < 3) { cout << "No" << nl; return; }
                    vis[v] = 1;
                } else {
                    if (hedge[v] != hedge[cur] - 1) { cout << "No" << nl; return; }
                }
                deg[v]--;
                if (deg[v] == 1) q.push(v);
            }
        }
        if (!hedge[cur]) flag = 1;
        if (hedge[cur] < 0) { cout << "No" << nl; return; }
    }
    if (flag) cout << "Yes" << nl;
    else cout << "No" << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}