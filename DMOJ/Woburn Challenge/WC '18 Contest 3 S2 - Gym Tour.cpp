#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 1e5 + 5;
int N, K, F, edges[MM], dep[MM], mx; vector<int> adj[MM]; bool gym[MM];
void dfs(int u, int pa) {
    edges[u] = 0;
    for (int v : adj[u]) {
        if (v != pa) {
            dep[v] = dep[u] + 1;
            dfs(v, u);
            if (gym[v]) edges[u] += edges[v] + 1, gym[u] = 1;
        }
    }
    if (gym[u]) mx = max(mx, dep[u]);
}
void solve(int tc) {
    cin >> N >> K >> F;
    for (int i = 1, x; i <= K; i++) { cin >> x; gym[x] = 1; }
    for (int i = 1, u, v; i < N; i++) { cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u); }
    dfs(1, 0);
    int without_dragon = 2*edges[1]-mx; gym[F] = 1; dfs(1, 0); int with_dragon = edges[1];
    cout << min(without_dragon, with_dragon) << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}