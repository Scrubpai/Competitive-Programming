#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int n, t[MM], mx[MM], in[MM]; vector<int> adj[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n; queue<int> q;
    for (int i=1, r; i<=n; i++) {
        cin >> t[i] >> r;
        for (int j=0, p; j<r; j++) {
            cin >> p; in[i]++;
            adj[p].push_back(i);
        }
        if (!in[i]) q.push(i);
    }
    int ans = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: adj[u]) {
            in[v]--; mx[v] = max(mx[v], t[u]);
            if (!in[v]) q.push(v), t[v] += mx[v];
        }
        ans = max(ans, t[u]);
    }
    cout << ans << '\n';
}