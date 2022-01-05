#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
#define nl '\n'
int N; vector<int> adj[MM]; bool vis[MM];
void dfs(int u, int pa) {
    for (int v : adj[u]) {
        if (v == pa) continue;
        dfs(v, u);
    }
    int pre = -1;
    for (int v : adj[u]) {
        if (vis[v] || v==pa) continue;
        if (pre==-1) pre=v;
        else { vis[pre]=vis[v]=1; cout << pre << " " << v << nl; pre=-1; }
    }
    if (pre != -1 && pa != -1 && !vis[pa]) { vis[u]=vis[pre]=1; cout << pa << " " << pre << nl; }
}
void solve(int tc) {
    cin >> N;
    for (int i=1, a, b; i<N; i++) {
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    cout << (N-1)/2 << nl;
    dfs(1, -1);
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }