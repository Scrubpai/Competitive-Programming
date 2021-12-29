#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, M, in[MM], dp[MM], ans; vector<int> adj[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for (int i=1, x, y; i<=M; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }
    queue<int> q;
    for (int i=1; i<=N; i++) if (!in[i]) q.push(i), dp[i] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            if (!--in[v]) q.push(v);
        }
        ans = max(ans, dp[u]);
    }
    printf("%d\n", ans);
}