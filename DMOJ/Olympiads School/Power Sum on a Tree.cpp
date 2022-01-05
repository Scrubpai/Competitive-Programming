#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;

const int MM = 3e5 + 5;
const int MX = 19;
const int MOD = 998244353;
ll n, q, u, v, k, anc[MM][MX+5], dep[MM], ans[MM][51], p[MM][51]; vector<int> adj[MM];

void dfs(int cur, int pa, int d) {
    anc[cur][0] = pa; dep[cur] = d;
    for (int nxt : adj[cur]) {
        if (nxt != pa) {
            for (int i = 1; i <= 50; i++) {
                ans[nxt][i] = (1LL * ans[cur][i] + p[d+1][i]) % MOD;
            }
            dfs(nxt, cur, d + 1);
        }
    }
}

void init() {
    for (int j = 1; j <= MX; j++) {
        for (int i = 1; i <= n; i++) {
            int par = anc[i][j-1];
            if (par != -1) anc[i][j] = anc[par][j-1];
        }
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    int d = dep[a] - dep[b];
    while (d > 0) {
        int i = log2(d);
        a = anc[a][i];
        d -= (1 << i);
    }
    if (a == b) return a;
    for (int i = MX; i >= 0; i--) {
        if (anc[a][i] != -1 && anc[b][i] != -1 && anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
    }
    return anc[a][0];
}

void solve(int tc) {

    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for (int i = 1; i < n; i++) {
        p[i][1] = i;
        for (int j = 2; j <= 50; j++) {
            p[i][j] = 1LL * p[i][j-1] * i % MOD;
        }
    }
    dfs(1, 0, 0); init();
    cin >> q;
    while (q--) {
        cin >> u >> v >> k;
        ll res = ((1LL * ans[u][k] + ans[v][k]) % MOD - ans[lca(u, v)][k] + MOD) % MOD;
        if (dep[lca(u, v)]) res = (res - ans[anc[lca(u, v)][0]][k] + MOD) % MOD;
        cout << res << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}