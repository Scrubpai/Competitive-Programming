#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5, LOG = 18;
int N, Q, dis[MM], t[MM], u[MM], v[MM], dsu[MM], anc[LOG][MM]; vector<int> adj[MM];
int fd(int x) { if (dsu[x] == x) return x; else return dsu[x] = fd(dsu[x]); }
void dfs(int a, int pa) {
    anc[0][a] = pa;
    for (int i=1; i<LOG; i++) anc[i][a] = anc[i-1][anc[i-1][a]];
    for (int b: adj[a])
        if (b != pa) { dis[b] = dis[a] + 1; dfs(b, a); }
}
int lca(int a, int b) {
    if (dis[a] < dis[b]) swap(a, b);
    for (int i=LOG-1; i>=0; i--) {
        if (dis[a] - (1<<i) >= dis[b]) a = anc[i][a];
    }
    if (a == b) return a;
    for (int i=LOG-1; i>=0; i--) {
        if (anc[i][a] != anc[i][b]) a = anc[i][a], b = anc[i][b];
    }
    return anc[0][a];
}
int get(int a, int b) {
    return dis[a] + dis[b] - 2 * dis[lca(a, b)];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> Q; dsu[N] = N; vector<int> queries;
    for (int i=1, a, b; i<N; i++) { cin >> a >> b; dsu[i] = i; adj[a].push_back(b); adj[b].push_back(a); }
    for (int i=1; i<=Q; i++) {
        cin >> t[i] >> u[i] >> v[i];
        if (t[i] == 1) queries.push_back(i);
    }
    int tmp = (int)queries.size()-1;
    for (int i=Q; i>=1; i--) {
        int fu = fd(u[i]), fv = fd(v[i]);
        if (t[i] == 2 && fu != fv) dsu[fu] = fv;
        else if (t[i] == 1) {
            if (fu != fv) queries[tmp] = -1;
            tmp--;
        }
    }
    dfs(1, 0);
    for (int i: queries) {
        if (i == -1) cout << -1 << '\n';
        else cout << get(u[i], v[i]) << '\n';
    }
}