/* Idea:
 *
 * Let red = 1, blue = -1
 * Then we want to find the number of paths such that the sum of weights on the path is equal to 1 or -1.
 *      If the sum is 1, then we can add a blue path to create a balanced cycle
 *      If the sum is -1, then we can add a red path to create a balanced cycle
 *
 * How to find number of such paths? Centroid Decomposition O(nlogn)
 *      Decompose the tree into smaller trees of a size N/2 using centroid
 *          Find the number of such paths going through the centroid, then block it
 *
 * Note that we have to subtract (n-1) from the answer since we also count the existing edges in the tree
 */

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
const int MM = 1e5+5;
int n, sz[MM]; bool done[MM]; vector<pi> adj[MM]; unordered_map<int, int> mp; ll ans;
void getsz(int u, int pa) {
    sz[u] = 1;
    for (pi p: adj[u]) {
        if (p.first != pa && !done[p.first]) { getsz(p.first, u); sz[u] += sz[p.first]; }
    }
}
int getcent(int rt, int pa, int tot) {
    for (pi p: adj[rt]) {
        int v = p.first;
        if (v != pa && !done[v] && 2 * sz[v] > tot) return getcent(v, rt, tot);
    }
    return rt;
}
void dfs(int u, int pa, int d, vector<int> &path) {
    ans += mp[1-d]; ans += mp[-1-d]; path.push_back(d);
    for (pi p: adj[u]) {
        int v = p.first, w = p.second;
        if (v != pa && !done[v]) dfs(v, u, d+w, path);
    }
}
void solve(int rt) {
    getsz(rt, 0); rt = getcent(rt, 0, sz[rt]); mp.clear(); mp[0] = 1; done[rt] = 1;
    for (pi p: adj[rt]) {
        int v = p.first, w = p.second; vector<int> path;
        if (!done[v]) {
            dfs(v, rt, w, path);
            for (int d: path) mp[d]++;
        }
    }
    for (pi p: adj[rt]) {
        if (!done[p.first]) solve(p.first);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i=1, a, b, w; i<n; i++) {
        char color; cin >> a >> b >> color; w = color == 'r' ? 1 : -1;
        adj[a].push_back({b, w}); adj[b].push_back({a, w});
    }
    solve(1); cout << ans - (n-1) << '\n';
}