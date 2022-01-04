#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
#define nl '\n'
int N, len[MM], len2[MM], dpa[MM]; vector<int> adj[MM];
void dfs1(int u, int pa) {
    for (int v : adj[u]) {
        if (v == pa) continue;
        dfs1(v, u);
        if (len[v] + 1 > len[u]) len2[u] = len[u], len[u] = len[v] + 1;
        else if (len[v] + 1 > len2[u]) len2[u] = len[v] + 1;
    }
}
void dfs2(int u, int pa) {
    for (int v : adj[u]) {
        if (v == pa) continue;
        if (len[v] + 1 == len[u]) dpa[v] = max(dpa[u], len2[u]) + 1;
        else dpa[v] = max(dpa[u], len[u]) + 1;
        dfs2(v, u);
    }
}
void solve(int tc) {
    cin >> N;
    for (int i=1, u, v; i<N; i++) {
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs1(1, 0); dfs2(1, 0);
    for (int i=1; i<=N; i++) cout << max(len[i], dpa[i]) + 1 << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }