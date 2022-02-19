#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3e5+5, mod = 1e9+7;
int N; char c[MM]; ll dp[MM][2], ans; vector<int> adj[MM];
void dfs(int u, int pa) {
    ll joinR = 0, joinB = 0, sumR = 0, sumB = 0;
    for (int v : adj[u]) {
        if (v == pa) continue;
        dfs(v, u);
        joinR = ((joinR + sumR) % mod * dp[v][0] % mod + joinR) % mod;
        joinB = ((joinB + sumB) % mod * dp[v][1] % mod + joinB) % mod;
        sumR = (sumR + dp[v][0]) % mod;
        sumB = (sumB + dp[v][1]) % mod;
    }
    if (c[u] == 'R') {
        dp[u][0] = (1 + sumR + joinR) % mod;
        dp[u][1] = (sumB + joinB) % mod;
        ans = (ans + dp[u][0] + joinB) % mod;
    } else {
        dp[u][0] = (sumR + joinR) % mod;
        dp[u][1] = (1 + sumB + joinB) % mod;
        ans = (ans + dp[u][1] + joinR) % mod;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1; i<=N; i++) cin >> c[i];
    for (int i=1, u, v; i<N; i++) {
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << '\n';
}