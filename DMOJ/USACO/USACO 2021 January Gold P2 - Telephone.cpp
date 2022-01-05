#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const int MM = 5e4+5;
#define nl '\n'
int N, K, b[MM], last[51], first[51], ok[51][51]; ll dp[MM]; vector<pi> adj[MM];
void solve(int tc) {
    cin >> N >> K;
    for (int i=1; i<=N; i++) cin >> b[i], dp[i]=1e18;
    for (int i=1; i<=K; i++) {
        for (int j=1; j<=K; j++) {
            char c; cin >> c;
            if (c=='1') ok[i][j]=1;
            else ok[i][j]=0;
        }
    }
    memset(last, -1, sizeof(last)); memset(first, -1, sizeof(first));
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=K; j++) {
            if (ok[j][b[i]] && last[j]!=-1) adj[last[j]].push_back({i, abs(i-last[j])});
            if (ok[j][b[i]] && first[j]!=-1) adj[first[j]].push_back({i, abs(i-first[j])});
        }
        last[b[i]]=i;
        if (first[b[i]]==-1) first[b[i]]=i;
    }
    memset(last, -1, sizeof(last));
    for (int i=N; i>=1; i--) {
        for (int j=1; j<=K; j++) {
            if (ok[j][b[i]] && last[j]!=-1) adj[last[j]].push_back({i, abs(i-last[j])});
            if (ok[j][b[i]] && first[j]!=-1) adj[first[j]].push_back({i, abs(i-first[j])});
        }
        last[b[i]]=i;
        if (first[b[i]]==-1) first[b[i]]=i;
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dp[1]=0; pq.push({0, 1});
    while (!pq.empty()) {
        ll cur = pq.top().second, d = pq.top().first; pq.pop();
        if (d>dp[cur]) continue;
        for (pi p : adj[cur]) {
            int v = p.first, c = p.second;
            if (dp[v] > dp[cur] + c) {
                dp[v] = dp[cur] + c;
                pq.push({dp[v], v});
            }
        }
    }
    if (dp[N]==1e18) cout << -1 << nl;
    else cout << dp[N] << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }