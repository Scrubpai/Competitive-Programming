/* Idea:
 *
 * Consider building a tree of the indices
 * Let the parent of every index i be j[i]+1. Also, let the array of values x[] in the question be a[].
 * Note that the root of the tree will be node N+1.
 *
 * Since j[i] is the largest index such that a[j[i]] <= a[i] + K, then a[j[i]+1] > a[i] + K.
 * So every parent node (i) will be the first index in a[] such that a[i] > a[child] + K
 *
 * Now, it comes down to constructing the array a[] using this tree.
 * Observe that a[parent] will be approximately K greater than a[child]
 * So we should define a[i] to be (some integer) * K + (some integer < K), where a[parent] - a[child] will be approximately 1*K + (some integer). Because a[i] - a[child] > K
 *
 * So let a[i] = h[i] * K + x[i], where h[i] is (max depth of the tree - dep[i]) and 0 <= x[i] <= K-1
 * Therefore, h[parent] - h[child] = 1
 * By simulating some cases, notice that the array h[] is non-decreasing from left to right (1 to N) because the lower indices will always be children in the tree
 *
 * Parent = j[i]+1 and child = i, height of child = h[i], height of parent = h[j[i]+1]
 * So we have to make sure that a[j[i]+1] - a[i] > K
 *      a[j[i]+1] = (h[i]+1) * K + x[j[i]+1]
 *      a[i] = h[i] * K + x[i]
 *
 *      a[j[i]+1] - a[i] = K + x[j[i]+1] - x[i]
 *      x[j[i]+1] - x[i] > 0
 *      x[j[i]+1] > x[i]
 *
 * Also, since j[i]+1 is the first index such a[j[i]+1] > a[i]+K, then j[i] will be the last index such that a[j[i]] <= a[i]+K
 *
 * For any 2 children (u, v where u < v) of the same parent, then h[u] = h[v], so you want x[v] >= x[u] always
 *      a[v] = h[v] * K + x[v]
 *      a[u] = h[u] * K + x[u]
 *
 *      Since v > u, a[v] >= a[u] by constraints of problem --> x[v] >= x[u]. We can just let x[v] > x[u].
 *
 * So now, the relationships between x[] are defined.
 * Note that this guarantees that a[j[i]] <= a[i] + K since 0 <= x[i] <= K-1
 *      If j[i] is on the same level as i (h[j[i]] = h[i]), then
 *          a[i] = h[i] * K + x[i]
 *          a[j[i]] = h[i] * K + x[j[i]]. Since j[i] >= i, then x[j[i]] >= x[i], 0 <= x[j[i]] - x[i] <= K-1 --> a[j[i]] = a[i] + x[j[i]] - x[i] <= a[i] + K
 *          a[j[i]+1] = h[j[i]+1] * K + x[j[i]+1] <-- parent <-- this will always be greater than a[i] and a[j[i]] because h[j[i]+1] > h[i]
 *              a[j[i]+1] = h[i] * K + K + x[j[i]+1] = a[i] + K + (x[j[i]+1] - x[i]) > a[i] + K
 *      If h[j[i]] = h[i] + 1
 *          a[j[i]] = h[i] * K + K + x[j[i]], where x[j[i]] < x[j[i]+1]
 *          a[i] = h[i] * K + x[i]
 *
 *          a[j[i]] = a[i] + K + x[j[i]] - x[i]
 *          Actually one more condition is necessary --> x[i] >= x[j[i]]. This will be guaranteed through the DFS
 *
 * To ensure that everything is satisfied, let K = N+1 since there are N+1 nodes. Then we can let each x[i] be distinct between 0 and K-1
 * Let x[N+1] = K-1, since N+1 is the root and the x[parent] is biggest
 *
 * DFS:
 *      When reaching a node, assign it the next lowest x value
 *      DFS through its children in decreasing order. This guarantees that every node i has an x value larger than i's children, but all smaller indexes at the same height as i get an x value smaller than i's children, since the DFS reaches them only after searching through all i's descendants
 *
 */

#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, K, h[MM], dep[MM], x[MM], j[MM], val, mx; vector<int> adj[MM];
void dfs(int u) {
    x[u] = val--; mx = max(mx, dep[u]);
    sort(adj[u].begin(), adj[u].end(), greater<>());
    for (int v: adj[u]) {
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N; K = N + 1;
    for (int i=1; i<=N; i++) {
        cin >> j[i];
        adj[j[i]+1].push_back(i);
    }
    val = K-1; dfs(N+1);
    for (int i=1; i<=N; i++) h[i] = mx - dep[i];
    cout << K << '\n';
    for (int i=1; i<=N; i++) cout << 1ll*h[i]*K+x[i] << '\n';
}