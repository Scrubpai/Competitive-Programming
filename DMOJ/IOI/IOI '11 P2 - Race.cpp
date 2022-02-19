/* Idea:
 *
 * We should count the minimum number of edges x that such that a path with x edges has length K
 * Brute force all possible paths using Centroid Decomposition
 *
 * When we divide and conquer each subtree from its centroid, keep a map where mp[i] stores the minimum edge count going through the centroid for a path of length i
 * Then when we dfs through the subtrees, ans = min(ans, cnt + mp[K-dis]) if there is a path of length K-dis stored in mp already
 *      where dis is the current path length and cnt is the number of edges traversed to reach this length
 * Then solve each sub-problem where the path does not go through the centroid
 */

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 2e5+5;
int sz[MM], k, ans=1e9; bool done[MM]; vector<pii> adj[MM]; map<int, int> global; // dis --> cnt
void getsz(int u, int pa) {
    sz[u] = 1;
    for (auto &[v, l]: adj[u]) {
        if (v != pa && !done[v]) { getsz(v, u); sz[u] += sz[v]; }
    }
}
int getcent(int u, int pa, int tot) {
    for (auto &[v, l]: adj[u]) {
        if (v != pa && !done[v] && 2 * sz[v] > tot) return getcent(v, u, tot);
    }
    return u;
}
void dfs(int u, int pa, int len, int cnt, map<int, int> &mp) {
    if (global.count(k - len)) ans = min(ans, global[k - len] + cnt);
    mp[len] = mp.count(len) ? min(mp[len], cnt) : cnt;
    for (auto &[v, l]: adj[u]) {
        if (v != pa && !done[v] && len+l <= k) dfs(v, u, len+l, cnt+1, mp);
    }
}
void solve(int rt) {
    getsz(rt, -1); rt = getcent(rt, -1, sz[rt]); done[rt] = 1; global.clear(); global[0] = 0;
    for (auto &[v, l]: adj[rt]) {
        if (!done[v]) {
            map<int, int> local;
            dfs(v, rt, l, 1, local);
            for (auto &[dis, cnt]: local) {
                if (!global.count(dis)) global[dis] = cnt;
                else global[dis] = min(global[dis], cnt);
            }
        }
    }
    for (auto &[v, l]: adj[rt]) {
        if (!done[v]) solve(v);
    }
}
int best_path(int N, int K, int H[][2], int L[]) {
    k = K;
    for (int i=0; i<N-1; i++) {
        adj[H[i][0]].push_back({H[i][1], L[i]});
        adj[H[i][1]].push_back({H[i][0], L[i]});
    }
    solve(0);
    return (ans == 1e9 ? -1: ans);
}