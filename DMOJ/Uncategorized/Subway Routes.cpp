#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 4e5+5;
#define nl '\n'
int N, dia, len[MM], cnt[MM]; ll num; vector<int> adj[MM];
void dfs(int u, int pa) {
    len[u] = 0; cnt[u] = 1;
    for (int v : adj[u]) {
        if (v == pa) continue;
        dfs(v, u);
        if (len[v] + len[u] + 1 > dia) {
            dia = len[v] + len[u] + 1;
            num = 1ll*cnt[u]*cnt[v];
        } else if (len[v] + len[u] + 1 == dia) {
            num += 1ll*cnt[u]*cnt[v];
        }
        if (len[v] + 1 > len[u]) len[u] = len[v] + 1, cnt[u] = cnt[v];
        else if (len[v] + 1 == len[u]) cnt[u] += cnt[v];
    }
}
void solve(int tc) {
    cin >> N;
    for (int i=1, u, v; i<N; i++) {
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << num << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }