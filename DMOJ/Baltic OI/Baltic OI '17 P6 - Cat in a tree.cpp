#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int N, D, dp[MM], ans; vector<int> adj[MM];
void dfs(int u, int pa) {
    deque<int> q;
    for (int v : adj[u]) {
        if (v == pa) continue;
        dfs(v, u);
        q.push_back(dp[v] + 1);
    }
    sort(q.begin(), q.end());
    while ((int)q.size() >= 2 && q[0] + q[1] < D) q.pop_front(), ans--;
    if (q.empty()) dp[u] = 0;
    else dp[u] = q[0] % D;
    if (!dp[u]) ans++;
}
int main() {
    cin >> N >> D;
    for (int i=1, x; i<N; i++) {
        cin >> x;
        adj[x].push_back(i); adj[i].push_back(x);
    }
    dfs(0, -1);
    printf("%d\n", ans);
}