#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5, mod = 1e9+7;
int N, M, in[MM], out[MM], dp[MM], cnt[MM]; vector<int> adj[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for (int i=0, u, v; i<M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++; out[u]++;
    }
    queue<int> q;
    for (int i=1; i<=N; i++) {
        if (!in[i]) q.push(i), cnt[i] = 1;
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            cnt[v]= (cnt[v] + cnt[u]) % mod;
            dp[v] = ((dp[v] + dp[u]) % mod + cnt[u]) % mod;
            in[v]--;
            if (!in[v]) q.push(v);
        }
    }
    int ans = 0;
    for (int i=1; i<=N; i++) {
        if (!out[i]) ans = (ans + dp[i]) % mod;
    }
    cout << ans << '\n';
    return 0;
}