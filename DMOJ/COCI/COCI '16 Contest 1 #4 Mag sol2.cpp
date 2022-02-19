#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+5;
struct frac {
    ll x, y;
    frac(ll x0, ll y0) { ll g = __gcd(x0, y0); x = x0/g; y = y0/g; }
    bool operator < (const frac &a) const { return x * a.y < a.x * y; }
};
int N, dis[MM], a[MM], mx[MM], mx2[MM], ch[MM]; vector<int> adj[MM]; frac ans(1e18, 1);
void dfs1(int u, int pa) {
    for (int v : adj[u]) {
        if (v == pa) continue;
        dfs1(v, u);
        if (dis[v] > mx[u]) mx2[u] = mx[u], mx[u] = dis[v], ch[u] = v;
        else if (dis[v] > mx2[u]) mx2[u] = dis[v];
    }
    if (a[u] == 1) dis[u] = mx[u]+1;
}
void dfs2(int u, int pa, int up) {
    ans = min(ans, frac{a[u], mx[u]+mx2[u]+1});
    ans = min(ans, frac{a[u], mx[u]+up+1});
    for (int v : adj[u]) {
        if (v == pa) continue;
        int tmp = 0;
        if (a[u] == 1) {
            if (v == ch[u]) tmp = max(up, mx2[u]);
            else tmp = max(up, mx[u]);
            tmp++;
        }
        dfs2(v, u, tmp);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1, u, v; i<N; i++) {
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for (int i=1; i<=N; i++) { cin >> a[i]; ans = min(ans, frac{a[i], 1}); }
    dfs1(1, 0); dfs2(1, 0, 0);
    cout << ans.x << '/' << ans.y << '\n';
}