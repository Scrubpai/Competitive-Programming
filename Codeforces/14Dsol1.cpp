#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))

int n, ans, len1, len2, maxd, far; vector<int> adj[205]; bool vis[205];

void dfs(int u, int pa, int no, int d) {
    if (u == no) return;
    if (d > maxd) { maxd = d; len1 = maxd; far = u; }
    for (int v : adj[u]) {
        if (v != pa) {
            dfs(v, u, no, d + 1);
        }
    }
}

void solve (int tc) {

    cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            maxd = 0; len1 = 0; far = i; dfs(i, 0, j, 0); maxd = 0; dfs(far, 0, j, 0); len2 = len1;
            len1 = 0; maxd = 0; far = j; dfs(j, 0, i, 0); maxd = 0; dfs(far, 0, i, 0);
            ans = max(ans, len1 * len2);
        }
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}