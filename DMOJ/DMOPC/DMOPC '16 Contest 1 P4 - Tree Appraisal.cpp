#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
int N; ll val[MM], dp[MM], sz[MM], par[MM], tot[MM], ans; vector<int> adj[MM];
void dfs1(int u, int pa) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == pa) continue;
        dfs1(v, u);
        sz[u] += sz[v]; dp[u] += sz[v] + dp[v];
    }
}
void dfs2(int u, int pa) {
    tot[u] = dp[u]*(N-sz[u]+1) + par[u]*sz[u];
    for (int v : adj[u]) {
        if (v == pa) continue;
        par[v] = par[u] + (dp[u]-dp[v]-sz[v]) + N-sz[v];
        tot[u] += (dp[u]-dp[v]-sz[v]) * sz[v];
        dfs2(v, u);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1; i<=N; i++) cin >> val[i];
    for (int i=1, a, b; i<N; i++) {
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs1(1, 0); dfs2(1, 0);
    for (int i=1; i<=N; i++) ans += val[i] * tot[i];
    cout << ans << '\n';
}