#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+5;
int N, M, in[MM], cnt; vector<int> adj[MM]; queue<int> q;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for (int i=0, u, v; i<M; i++) {
        cin >> u >> v;
        adj[u].push_back(v); in[v]++;
    }
    for (int i=1; i<=N; i++) if (!in[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop(); cnt++;
        for (int v : adj[u]) {
            in[v]--;
            if (!in[v]) q.push(v);
        }
    }
    printf("%s\n", cnt==N?"Y":"N");
    return 0;
}