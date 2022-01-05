#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
#define nl '\n'
#define INF 0x3f3f3f3f
int N, M, C, m[1005], dp[1005][1005]; vector<int> adj[1005];
void solve(int tc) {
    cin >> N >> M >> C;
    //dp[i][j]: max amt of money if bessie is at city i at time j
    for (int i = 1; i <= N; i++) cin >> m[i];
    for (int i = 1, a, b; i <= M; i++) {
        cin >> a >> b;
        adj[b].push_back(a);
    }
    memset(dp, -INF, sizeof(dp)); dp[1][0] = 0;
    for (int t = 1; 1000*t - C*t*t > 0; t++) {
        for (int u = 1; u <= N; u++) {
            for (int v : adj[u]) {
                dp[u][t] = max(dp[u][t], dp[v][t-1] + m[u] - C * (2*t - 1));
            }
        }
    }
    int ans = 0;
    for (int t = 1; 1000*t - C*t*t > 0; t++) ans = max(ans, dp[1][t]);
    cout << ans << nl;
}
int32_t main() {
    //freopen("", "r", stdin); freopen("", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}