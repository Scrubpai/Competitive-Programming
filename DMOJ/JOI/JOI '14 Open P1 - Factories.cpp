/* Idea:

So we are given some companies X[] and Y[] such that we have to find the minimum distance between any factory in X[] to any factory in Y[].

We should build a centroid tree using centroid decomposition.
    Let pre[i] be the parent of node i in the centroid tree
        If node i is a level-j centroid in the original tree, then pre[i] will be the level (j-1) centroid in the corresponding original subtree (the direct parent in the centroid tree)

    Let lvl[i] be the centroid level of node i

    Using a centroid tree, we can decompose the tree into O(NlogN) different paths, which we will store in dis[lvl][u]

        Basically, dis[i][j] will store the distance from the level-i centroid in node j's subtree (in the original tree) to node j.

    Key Idea: Any path in the original tree can be separated into 2logN steps in the centroid tree

So how should we query using this dis[i][j]?
    Well using the centroid tree, we can decompose any path A->B to A->C->B in the original tree, where C is the centroid of path A->B.

    C will also be the lowest common ancestor of A and B in the centroid tree. This is good because the height of the centroid tree is at most logN

    So let dp[i] be the minimum distance to reach node i from a factory in its subtree in the CENTROID TREE.

    So then we can first loop all factores in X[].
        Let's say the current factory in X[] is at node u

        Then for all parents (p) of node u in the centroid tree (including node u), dp[p] = min(dp[p], dis[lvl[p]][u])

    Then we can loop all factories in Y[].
        For each node u in the centroid tree, u represents the centroid which can connect two nodes A and B in its subtree, where node A will represent a factory from company X[] and node B will represent a factory from company Y[]

        Since dp[u] already stores the minimum distance to reach node u from A in its subtree, then we can just join this to another B in its subtree

        And u must be an ancestor of both A and B

        So we can just loop all parents(p) of B (including itself), and ans = min(ans, dp[p] + dis[lvl[p]][B])

However, there is a slight trick.
    If we loop n times in the query, it will TLE
        Because the constraints only guarantee that the sum of S and the sum of T <= 1e6, but N is still <= 5e5

    So we can optimize this using a tmp[] and cnt.
        You only care about the nodes that are actually being queried, and you can just store them in a tmp[] array

    After you find your answer, we can just reset the dp[] to infinity by only resetting nodes in tmp[] to infinity rather than all n nodes
*/

#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
typedef long long ll;
typedef pair<int, ll> pil;
int sz[MM], pre[MM], lvl[MM], tmp[20*MM], cnt; vector<pil> adj[MM]; bool done[MM]; ll dis[20][MM], dp[MM];
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
void dfs(int u, int pa, int level, ll d) {
    dis[level][u] = d;
    for (auto &[v, l]: adj[u]) {
        if (v != pa && !done[v]) dfs(v, u, level, d+l);
    }
}
void solve(int rt, int pa, int level) {
    getsz(rt, -1); rt = getcent(rt, -1, sz[rt]);
    done[rt] = 1; pre[rt] = pa; lvl[rt] = level;
    dfs(rt, -1, level, 0);
    for (auto &[v, l]: adj[rt]) {
        if (!done[v]) solve(v, rt, level+1);
    }
}
void Init(int N, int A[], int B[], int D[]) {
    for (int i=0; i<N; i++) dp[i] = 1e18;
    for (int i=0; i<N-1; i++) {
        adj[A[i]].push_back({B[i], D[i]});
        adj[B[i]].push_back({A[i], D[i]});
    }
    solve(0, -1, 0);
}
long long Query(int S, int X[], int T, int Y[]) {
    cnt = 0;
    for (int i=0; i<S; i++) {
        for (int j=X[i]; j!=-1; j=pre[j]) {
            dp[j] = min(dp[j], dis[lvl[j]][X[i]]);
            tmp[++cnt] = j;
        }
    }
    ll ans = 1e18;
    for (int i=0; i<T; i++) {
        for (int j=Y[i]; j!=-1; j=pre[j]) {
            if (dp[j] != (ll)1e18) ans = min(ans, dp[j] + dis[lvl[j]][Y[i]]);
        }
    }
    for (int i=1; i<=cnt; i++) dp[tmp[i]] = 1e18;
    return ans;
}