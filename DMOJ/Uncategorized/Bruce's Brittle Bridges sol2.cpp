#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 2e5+5;
#define nl '\n'
int N, v[MM], root[MM], vis[MM]; ll dp[MM]; vector<pii> adj1[MM]; vector<int> adj2[MM];
void dfs1(int cur, int pa, int rt) {
    vis[cur] = 1; root[cur] = rt; dp[rt] += v[cur];
    for (pii p : adj1[cur]) {
        int u = p.first, t = p.second;
        if (u == pa || t == 1) continue;
        dfs1(u, cur, rt);
    }
}
ll dfs2(int cur, int pa) {
    ll ret = 0;
    for (int u : adj2[cur]) {
        if (u == pa) continue;
        ret = max(ret, dfs2(u, cur));
    }
    return ret + dp[cur];
}
void solve(int tc) {
    cin >> N;
    for (int i=1; i<=N; i++) cin >> v[i];
    for (int i=1, a, b, t; i<N; i++) {
        cin >> a >> b >> t;
        adj1[a].emplace_back(b, t);
        adj1[b].emplace_back(a, t);
    }
    for (int i=1; i<=N; i++) {
        if (!vis[i]) dfs1(i, 0, i);
    }
    for (int i=1; i<=N; i++) {
        for (pii p : adj1[i]) {
            if (root[p.first] != root[i]) adj2[root[i]].push_back(root[p.first]);
        }
    }
    cout << dfs2(1, 0) << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }