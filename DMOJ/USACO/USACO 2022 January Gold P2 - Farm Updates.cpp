/* Idea:
 *
 * Loop the queries in reverse order. There are 3 cases:
 * 1) The query is 'A.' Do nothing
 *      Before this edge was added, both farms must have already been active
 *      We considered this when either farm was deactivated or both farms were never deactivated
 *      So if this edge was never removed, just add it into the adj list in the beginning. Once one of the farms is deactivated, it is always after this query, so it will be considered first.
 * 2) The query is 'D' x
 *      Each farm can only be deactivated once.
 *      Before this query, x was active. So it was relevant.
 *      Mark all the irrelevant farms that are currently connected to x as relevant.
 *      Because before this query, all those farms were also connected to x.
 *          If a farm was not connected to x before this query, it must have been removed or not added in the first place
 *          If it got connected to x after this query, then x must be active <-- Contradiction
 * 3) The query is 'R' x y
 *      Add an edge between x and y.
 *      Before this query, there must have been an edge between x and y.
 *      If x is currently relevant and y is irrelevant
 *          Then before this query, both x and y are relevant and all nodes connected to x and y are relevant
 *          If x was irrelevant before this query, x must have been deactivated AND all the nodes it was connected to were deactivated
 *          But once that happens, then it can never become relevant again <-- Contradiction
 *          So x was relevant. And there was an edge between x and y. So y was relevant
 *      If y is currently relevant and x is irrelevant
 *          Mark all nodes as relevant
 *
 * O(N+Q) DFS
 */

#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
struct query { char type; int time, x; };
int N, Q, d[MM], ans[MM], a[MM], b[MM], cnt; vector<int> adj[MM];
void dfs(int u, int val) {
    if (ans[u] == -1) {
        ans[u] = val;
        for (int v: adj[u]) {
            dfs(v, val);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> Q; vector<query> queries; set<int> st;
    for (int i=1; i<=N; i++) d[i] = Q+1;
    for (int i=1, x, y; i<=Q; i++) {
        char op; cin >> op;
        if (op == 'D') {
            cin >> x;
            d[x] = i;
            queries.push_back({op, i, x});
        } else if (op == 'A') {
            cin >> x >> y;
            a[++cnt] = x; b[cnt] = y; st.insert(cnt);
        } else {
            cin >> x; st.erase(x);
            queries.push_back({op, i, x});
        }
    }
    memset(ans, -1, sizeof(ans));
    for (int x: st) adj[a[x]].push_back(b[x]), adj[b[x]].push_back(a[x]);
    for (int i=1; i<=N; i++) {
        if (d[i] == Q+1) {
            dfs(i, Q);
        }
    }
    for (int i=(int)queries.size()-1; i>=0; i--) {
        query q = queries[i];
        if (q.type == 'D') {
            if (ans[q.x] == -1) dfs(q.x, q.time-1);
        } else {
            int u = a[q.x], v = b[q.x]; adj[u].push_back(v); adj[v].push_back(u);
            if (ans[u] != -1 || ans[v] != -1) dfs(u, q.time-1), dfs(v, q.time-1);
        }
    }
    for (int i=1; i<=N; i++) cout << ans[i] << '\n';
}