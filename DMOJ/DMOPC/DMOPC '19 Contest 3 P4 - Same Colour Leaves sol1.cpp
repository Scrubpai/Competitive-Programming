#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3e5+5, mod = 1e9+7;
int N; char color[MM]; vector<int> adj[MM]; ll dp[MM][2], ans;
void dfs(int u, int pa) {
    dp[u][0] = dp[u][1] = 1;
    for (int v : adj[u]) {
        if (v == pa) continue;
        dfs(v, u);
        dp[u][0] = dp[u][0] * (dp[v][0] + 1) % mod;
        dp[u][1] = dp[u][1] * (dp[v][1] + 1) % mod;
    }
    if (color[u] == 'R') {
        dp[u][0]--;
        ans = (ans + dp[u][0]) % mod;
        ans = (ans + dp[u][1]) % mod;
        for (int v : adj[u]) {
            if (v == pa) continue;
            ans = (ans - dp[v][0] + mod) % mod;
        }
    } else {
        dp[u][1]--;
        ans = (ans + dp[u][0]) % mod;
        ans = (ans + dp[u][1]) % mod;
        for (int v : adj[u]) {
            if (v == pa) continue;
            ans = (ans - dp[v][1] + mod) % mod;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1; i<=N; i++) cin >> color[i];
    for (int i=1, u, v; i<N; i++) {
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0);
    printf("%lld\n", ans);
}