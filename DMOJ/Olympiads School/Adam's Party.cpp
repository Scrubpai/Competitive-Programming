#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
const int MM = 2e5+5, mod = 1e9+7;
int N, M, K, d1[MM], d2[MM]; vector<int> adj[MM];
void bfs(int st, int d[]) {
    queue<int> q; q.push(st); d[st]=0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (d[v] < 0) { q.push(v); d[v] = d[u] + 1; }
        }
    }
}
ll qpow(ll b, ll exp) {
    ll ret = 1;
    for (; exp; exp>>=1) {
        if (exp & 1) ret = (ret * b) % mod;
        b = (b * b) % mod;
    }
    return ret;
}
void solve(int tc) {
    cin >> N >> M >> K;
    memset(d1, -1, sizeof(d1)); memset(d2, -1, sizeof(d2));
    for (int i=1, u, v; i<=M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1, d1); bfs(N, d2);
    int ans = 0;
    for (int i=2; i<N; i++) {
        ans += (d1[i] != -1 && d2[i] != -1 && d1[i] <= K && d2[i] <= K);
    }
    cout << qpow(2, ans) << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }