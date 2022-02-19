#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, int> pl;
const int MM = 2e5+5;
int N, sz[MM], ans=(int)1e9; bool done[MM]; vector<pi> adj[MM]; ll K; map<ll, int> mp;
void getsz(int u, int pa) {
    sz[u] = 1;
    for (pi p: adj[u]) {
        if (p.f != pa && !done[p.f]) { getsz(p.f, u); sz[u] += sz[p.f]; }
    }
}
int getcent(int u, int pa, int tot) {
    for (pi p: adj[u]) {
        if (p.f != pa && !done[p.f] && 2 * sz[p.f] > tot) return getcent(p.f, u, tot);
    }
    return u;
}
void dfs(int u, int pa, int cnt, ll d, vector<pl> &path) {
    ans = min(ans, (mp[K-d] || d == K) ? cnt + mp[K-d] : (int)1e9); path.push_back({d, cnt});
    for (pi p: adj[u]) {
        if (p.f != pa && !done[p.f]) dfs(p.f, u, cnt+1, d+p.s, path);
    }
}
void solve(int rt) {
    getsz(rt, 0); rt = getcent(rt, 0, sz[rt]); done[rt] = 1; mp.clear(); mp[0] = 0;
    for (pi p: adj[rt]) {
        if (!done[p.f]) {
            vector<pl> path;
            dfs(p.f, rt, 1, p.s, path);
            for (pl d: path) if (d.f) mp[d.f] = !mp[d.f] ? d.s : min(mp[d.f], d.s);
        }
    }
    for (pi p: adj[rt]) {
        if (!done[p.f]) solve(p.f);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K;
    for (int i=1, u, v, w; i<N; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }
    solve(1);
    cout << (ans == (int)1e9 ? -1 : ans) << '\n';
}