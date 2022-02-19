/* Idea:

During the centroid decomposition, at each centroid subtree, there are 2 ways to update the number of paths for each node (cnt[i]). Let's say the current centroid is c.
    1) Turn on/off each subtree connected to c
        First, insert all distances from c to any connected node (that is not blocked) to the frequency map. 
        
        Then, we can loop each subtree, and disable that subtree. In other words, remove all the distances in this subtree from the map.

        Then for each node u in the subtree whose distance is d from the centroid, cnt[u] += freq[K-d]. This works because by disabling the subtree, you are only considering the paths that must contain both u and c.

        Also, for every child v of u, cnt[u] += cnt[v]. Because if there is a way to reach node v from some other node not in the subtree with length K, then that path will also contain the parent node u.

        Then make sure to add the distances back to freq (enable the subtree again).

        For the centroid c itself, just update cnt[c] individually. cnt[c] += (total number of paths of length K for the current iteration in the centroid decomposition)

    2) Loop subtrees left to right, and then right to left
        For the adjacency list of c, first loop from left to right (i=0 to adj[c].size()-1)
            Update cnt[u] along the way - cnt[u] += freq[K-d], then for all d freq[d]++
            
            By the end of this loop, all the paths from the previous (prefix) subtrees to node u with length K will contribute to cnt[u].

        Then clear the frequency map

        For the adjacency list of c, now loop from right to left (i=adj[c].size()-1 to 0)
            Update cnt[u] along the way - cnt[u] += freq[K-d], then for all d freq[d]++

            By the end of this loop, all the paths from the subtrees AFTER node u (suffix) with length K will contribute to cnt[u]

        Since for each subtree, you have considered paths which lead to nodes in both the previous subtrees and later subtrees, then cnt[u] will be updated correctly
*/

#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
typedef pair<int, int> pii;
int N, K, sz[MM], ans[MM], cnt[MM], tot; bool done[MM]; vector<pii> adj[MM]; map<int, int> freq;
void getsz(int u, int pa) {
    sz[u] = 1;
    for (auto &[v, l]: adj[u])
        if (v != pa && !done[v]) { getsz(v, u); sz[u] += sz[v]; }
}
int getcent(int u, int pa, int tot) {
    for (auto &[v, l]: adj[u])
        if (v != pa && !done[v] && 2 * sz[v] > tot) return getcent(v, u, tot);
    return u;
}
void getdist(int u, int pa, int d, vector<int> &path) {
    path.push_back(d);
    for (auto &[v, l]: adj[u])
        if (v != pa && !done[v] && d+l<=K) getdist(v, u, d+l, path);
}
void calctot(int cent, int u, int pa, int d, vector<int> &path) {
    tot += freq[K-d]; ans[cent] += freq[K-d]; path.push_back(d); cnt[u] = 0;
    for (auto &[v, l]: adj[u])
        if (v != pa && !done[v] && d+l<=K) calctot(cent, v, u, d+l, path);
}
void dfs(int u, int pa, int d) {
    for (auto &[v, l]: adj[u]) {
        if (v != pa && !done[v] && d+l<=K) {
            dfs(v, u, d+l);
            cnt[u] += cnt[v];
        }
    }
    cnt[u] += freq[K-d];
    ans[u] += cnt[u];
}
void solve(int rt) {
    getsz(rt, 0); rt = getcent(rt, -1, sz[rt]); freq.clear(); freq[0] = 1; done[rt] = 1;
    for (auto &[v, t]: adj[rt]) {
        if (!done[v]) {
            vector<int> path;
            calctot(rt, v, 0, t, path);
            for (int d: path) freq[d]++;
        }
    }
    for (auto &[v, t]: adj[rt]) {
        if (!done[v]) {
            vector<int> path;
            getdist(v, 0, t, path);
            for (int d: path) freq[d]--;
            dfs(v, 0, t);
            for (int d: path) freq[d]++;
        }
    }
    for (auto &[v, t]: adj[rt])
        if (!done[v]) solve(v);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K;
    for (int i=1, a, b, t; i<N; i++) {
        cin >> a >> b >> t;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }
    solve(1);
    for (int i=1; i<=N; i++) {
        if (!ans[i]) cout << "0 / 1\n";
        else {
            int g = __gcd(ans[i], tot);
            cout << ans[i]/g << " / " << tot/g << '\n';
        }
    }
}