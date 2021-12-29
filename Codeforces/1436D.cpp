#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define nl '\n'
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))

const int MM = 2e5 + 5;
ll n, a[MM], leafs[MM], ans; vector<int> adj[MM];

void dfs(int u) {
    if (adj[u].empty()) { leafs[u] = 1; ans = max(ans, a[u]); return; }
    for (int v : adj[u]) {
        dfs(v);
        leafs[u] += leafs[v];
        a[u] += a[v];
    }
    ll capacity = leafs[u] * ans;
    if (capacity < a[u]) {
        ll rem = a[u] - capacity;
        ans += (ll)ceil(1.0 * rem / leafs[u]);
    }
}

void solve(int tc) {

    cin >> n;
    for (int i = 2, p; i <= n; i++) {
        cin >> p;
        adj[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs(1);
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}