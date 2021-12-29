#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 3e5 + 5;
#define nl '\n'
int n; vector<pi> adj[MM]; ll ans, w[MM], dp[MM][2];
void dfs(int u, int pa) {
    ll mx1 = 0, mx2 = 0; dp[u][1] = w[u];
    for (pi p : adj[u]) {
        int v = p.first, c = p.second;
        if (v == pa) continue;
        dfs(v, u);
        //0 means add, 1 means no add
        ll mx = max(dp[v][0], dp[v][1]) - c;
        dp[u][0] = max(dp[u][0], mx + w[u]);
        if (mx > mx1) mx2 = mx1, mx1 = mx;
        else if (mx > mx2) mx2 = mx;
    }
    ans = max(ans, w[u] + mx1 + mx2);
    ans = max({ans, dp[u][0], dp[u][1]});
}
void solve(int tc) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1, u, v, c; i < n; i++) {
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    dfs(1, 0);
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}