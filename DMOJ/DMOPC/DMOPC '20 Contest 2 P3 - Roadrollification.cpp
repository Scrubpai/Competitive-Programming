#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MM = 2e5 + 5;
ll n, a[MM], in[MM], ans, tot[MM], tot2[MM]; int ord[MM], x[MM], y[MM], idx; bool vis[MM]; queue<int> q; vector<int> adj[MM];

void dfs(int cur) {
    vis[cur] = 1; tot[cur] = a[cur];
    for (int v : adj[cur]) {
        if (!vis[v]) dfs(v);
        tot[cur] += tot[v];
    }
}

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> a[i]; tot2[i] = a[i]; }
    for (int i = 1; i < n; i++) {
        cin >> x[i] >> y[i];
        adj[x[i]].push_back(y[i]);
        in[y[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            dfs(i);
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int v : adj[cur]) {
            tot2[v] += tot2[cur];
        }
        ord[++idx] = cur;
        for (int nxt : adj[cur]) {
            in[nxt]--;
            if (!in[nxt]) q.push(nxt);
        }
    }
    for (int i = 1; i <= n; i++) {
        ans += 1ll * (a[ord[i]] * (tot[ord[i]] - 1));
    }
    ll add = 0;
    for (int i = 1; i < n; i++) {
        int u = x[i], v = y[i];
        //all the stuff that reaches v can reach all the children of u
        add = max(add, (tot2[v] - tot2[u]) * (tot[u] - tot[v]));
    }
    cout << ans + add << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}