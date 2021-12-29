#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 1e5 + 5;
#define nl '\n'
int n, m, in[MM]; vector<pii> adj[MM];
void solve(int tc) {
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v; in[v]++;
        adj[u].push_back({i, v});
    }
    int st = -1;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            if (st == -1) st = i;
            else { cout << -1 << nl; return; }
        }
    }
    int ans = 0, cnt = 0;
    queue<int> q; q.push(st);
    while (!q.empty()) {
        int cur = q.front(); q.pop(); cnt++;
        int num = 0;
        for (pii p : adj[cur]) {
            int v = p.second, d = p.first;
            in[v]--;
            if (!in[v]) ans = max(ans, d), q.push(v), num++;
        }
        if (num > 1) { cout << -1 << nl; return; }
    }
    if (cnt != n) cout << -1 << nl;
    else cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}