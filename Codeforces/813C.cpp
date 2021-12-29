#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
#define nl '\n'
int n, disA[MM], disB[MM], x; vector<int> adj[MM];
void dfs(int u, int pa, int dis[]) {
    for (int v : adj[u]) {
        if (v != pa) {
            dis[v] = dis[u] + 1;
            dfs(v, u, dis);
        }
    }
}
void solve(int tc) {
    cin >> n >> x;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(1, 0, disA); dfs(x, 0, disB);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (disB[i] < disA[i]) ans = max(ans, 2*disA[i]); //disA[i] is depth as well
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}