#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))

int n, a[5005], cnt; vector<int> adj[5005]; vector<pii> ord; bool vis[5005];

void dfs(int cur, int pa) {
    for (int v : adj[cur]) {
        if (v != pa && !vis[v]) {
            ord.push_back({cur, v}); vis[v] = 1;
            dfs(v, cur);
        }
    }
}

void solve(int tc) {

    cin >> n; ord.clear(); cnt = 1; ms(vis, 0);
    for (int i = 1; i <= n; i++) { cin >> a[i]; adj[i].clear(); }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] != a[j]) adj[i].push_back(j), adj[j].push_back(i);
        }
    }
    vis[1] = 1;
    dfs(1, -1); 
    if (ord.size() != n - 1) cout << "NO" << nl;
    else {
        cout << "YES" << nl;
        for (pii p : ord) cout << p.first << " " << p.second << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}