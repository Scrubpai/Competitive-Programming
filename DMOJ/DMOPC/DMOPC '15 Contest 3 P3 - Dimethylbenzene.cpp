#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long MAXN = numeric_limits<long long>::max();
typedef long long ll;

int N, M, u, v; int vis[21]; int cnt[21]; vector<int> adj[21]; bool cycle;

void dfs(int cur) {
    vis[cur] = 1;
    for (int v : adj[cur]) {
        if (!cycle) {
            if (vis[v]==1 && cnt[cur]-cnt[v]+1==6) {
                cout << "YES" << endl; cycle = true; break;
            } else if (vis[v]==0) { cnt[v] = cnt[cur] + 1; dfs(v); }
        }
    }

    vis[cur] = 2;
}

void solve() {
    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    dfs(1); cnt[1] = 1;
    if (!cycle) cout << "NO" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}