#include <bits/stdc++.h>
using namespace std;
const int MM = (1<<17)+5;
int N, M, dp[MM]; vector<int> adj[MM];
void dfs(int u, int mask, int d) {
    if (dp[mask] < d) return;
    dp[mask] = d;
    for (int v: adj[u]) {
        int nmask = mask^(1<<v);
        dfs(v, nmask, d+1);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i=1, u, v; i<=M; i++) {
        cin >> u >> v; u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    memset(dp, 0x3f3f3f3f, sizeof(dp)); dp[0] = 0;
    for (int i=0; i<N; i++) {
        dfs(i, (1<<i), 1);
    }
    int ans = 0;
    for (int i=0; i<(1<<N); i++) ans += dp[i];
    cout << ans << '\n';
}