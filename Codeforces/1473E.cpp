#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 2e5+5;
#define nl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
int n, m; ll dp[MM][2][2]; vector<pii> adj[MM];
void solve(int tc) {
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        adj[u].emplace_back(make_pair(v, w));
        adj[v].emplace_back(make_pair(u, w));
    }
    priority_queue<array<ll, 4>, vector<array<ll, 4>>, greater<array<ll, 4>>> pq;
    memset(dp, INF, sizeof(dp));
    dp[1][0][0] = 0;
    pq.push({0, 1, 0, 0});
    while (!pq.empty()) {
        auto [d, u, f1, f2] = pq.top(); pq.pop();
        if (d > dp[u][f1][f2]) continue;
        for (pii nxt : adj[u]) {
            int v = nxt.first, c = nxt.second;
            if (dp[v][f1][f2] > dp[u][f1][f2] + c) {
                dp[v][f1][f2] = dp[u][f1][f2] + c;
                pq.push({dp[v][f1][f2], v, f1, f2});
            }
            if (!f1) {
                if (dp[v][1][f2] > dp[u][0][f2]) {
                    dp[v][1][f2] = dp[u][0][f2];
                    pq.push({dp[v][1][f2], v, 1, f2});
                }
            }
            if (!f2) {
                if (dp[v][f1][1] > dp[u][f1][0] + 1ll*2*c) {
                    dp[v][f1][1] = dp[u][f1][0] + 1ll*2*c;
                    pq.push({dp[v][f1][1], v, f1, 1});
                }
            }
            if (!f1 && !f2) {
                if (dp[v][1][1] > dp[u][0][0] + c) {
                    dp[v][1][1] = dp[u][0][0] + c;
                    pq.push({dp[v][1][1], v, 1, 1});
                }
            }
        }
    }
    for (int i = 2; i <= n; i++) cout << dp[i][1][1] << ' ';
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}