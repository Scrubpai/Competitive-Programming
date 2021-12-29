#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5, LOG=17;
struct event { int p, t, id; };
int N, Q, v[MM], dep[MM], best[MM], anc[LOG][MM], st[MM], top=1; vector<int> adj[MM];
void dfs(int u, int pa) {
    for (int i=1; i<LOG; i++) {
        if (anc[i-1][u] != -1) anc[i][u] = anc[i-1][anc[i-1][u]];
    }
    for (int nxt : adj[u]) {
        if (nxt == pa) continue;
        if (v[nxt] <= v[best[u]]) best[nxt] = nxt;
        else best[nxt] = best[u];
        dep[nxt] = dep[u] + 1;
        dfs(nxt, u);
    }
}
int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int i=LOG-1; i>=0; i--) {
        if (dep[a] - (1<<i) >= dep[b]) a = anc[i][a];
    }
    if (a == b) return anc[0][a];
    for (int i=LOG-1; i>=0; i--) {
        if (anc[i][a] != -1 && anc[i][b] != -1 && anc[i][a] != anc[i][b]) a = anc[i][a], b = anc[i][b];
    }
    return anc[0][a];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N; vector<event> line;
    for (int i=1, l, r; i<=N; i++) {
        cin >> l >> r >> v[i];
        line.push_back({l, 1, i}); line.push_back({r, -1, i});
    }
    sort(line.begin(), line.end(), [](event a, event b) { return a.p < b.p; });
    memset(anc, -1, sizeof(anc));
    for (event e : line) {
        if (e.t == 1) { //left
            adj[st[top]].push_back(e.id);
            adj[e.id].push_back(st[top]);
            anc[0][e.id] = st[top];
            st[++top] = e.id;
        } else { //right
            top--;
        }
    }
    v[0] = 2e9; dfs(0, -1);
    cin >> Q;
    for (int i=1, a, b; i<=Q; i++) {
        cin >> a >> b;
        printf("%d\n", best[lca(a, b)]?best[lca(a, b)]:-1);
    }
}