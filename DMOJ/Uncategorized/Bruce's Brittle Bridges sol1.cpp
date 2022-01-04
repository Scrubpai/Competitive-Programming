#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 2e5+5;
#define nl '\n'
int N, v[MM]; ll dp[MM][2]; vector<pii> adj[MM];
void dfs(int u, int pa) {
    dp[u][0] = dp[u][1] = v[u];
    vector<ll> vec;
    for (pii p : adj[u]) {
        int nxt = p.first, t = p.second;
        if (nxt == pa) continue;
        dfs(nxt, u);
        if (t>1) dp[u][0] += dp[nxt][0], vec.push_back(dp[nxt][1] - dp[nxt][0]);
        else vec.push_back(dp[nxt][1]);
    }
    sort(vec.begin(), vec.end());
    if (!vec.empty()) dp[u][1] = dp[u][0] + vec.back();
}
void solve(int tc) {
    cin >> N;
    for (int i=1; i<=N; i++) cin >> v[i];
    for (int i=1, a, b, t; i<N; i++) {
        cin >> a >> b >> t;
        adj[a].emplace_back(b, t);
        adj[b].emplace_back(a, t);
    }
    dfs(1, 0);
    cout << dp[1][1] << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }