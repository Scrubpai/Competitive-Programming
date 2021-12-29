#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5, mod=1e9+7;
#define nl '\n'
int N; ll dp[MM][2]; vector<int> adj[MM];
void dfs(int u, int pa) {
    dp[u][0] = dp[u][1] = 1;
    for (int v : adj[u]) {
        if (v == pa) continue;
        dfs(v, u);
        dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][1]) % mod) % mod;
        dp[u][1] = (dp[u][1] * dp[v][0]) % mod;
    }
}
void solve(int tc) {
    cin >> N;
    for (int i=1, x, y; i<N; i++) {
        cin >> x >> y;
        adj[x].push_back(y); adj[y].push_back(x);
    }
    dfs(1, 0); cout << (dp[1][0] + dp[1][1]) % mod << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }