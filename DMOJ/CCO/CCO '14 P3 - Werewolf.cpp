#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
const int MM = 201, mod = 1e9+7;
int N, W, M, in[MM]; ll dp[MM][MM][2]; char ch; vector<pi> adj[MM];
void dfs(int u) {
    dp[u][0][0] = dp[u][1][1] = 1;
    for (pi p : adj[u]) {
        int v = p.first, t = p.second;
        dfs(v);
        for (int i=W; i>=0; i--) {
            ll ans0 = 0, ans1 = 0;
            for (int j=0; j<=i; j++) {
                ans0 = (ans0 + dp[u][j][0] * (dp[v][i-j][0] + dp[v][i-j][1])) % mod;
                ans1 = (ans1 + dp[u][j][1] * dp[v][i-j][t^1]) % mod;
            }
            dp[u][i][0] = ans0; dp[u][i][1] = ans1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> W >> M;
    for (int i=0, a, b; i<M; i++) {
        cin >> ch >> a >> b; in[b]++;
        if (ch == 'A') adj[a].push_back({b, 1});
        else adj[a].push_back({b, 0});
    }
    for (int i=1; i<=N; i++) {
        if (!in[i]) adj[0].push_back({i, 1});
    }
    dfs(0);
    cout << dp[0][W][0] << '\n';
}