#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> pii;
const int MM = 1e5+5;
int N, M, A, B, v, d; vector<pii> adj[MM]; ll dis[MM], C;
bool chk(int k) {
    queue<int> q; vector<bool> vis(N+1); memset(dis, 0x3f, sizeof(dis)); dis[A] = 0; q.push(A); vis[A] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (pii p : adj[u]) {
            int id = p.first; tie(v, d) = p.second;
            if (id <= k && dis[v] > dis[u] + d) {
                dis[v] = dis[u] + d;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return dis[B] <= C;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for (int i=1, a, b, c; i<=M; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({i, {b, c}});
        adj[b].push_back({i, {a, c}});
    }
    cin >> A >> B >> C;
    int lo = 1, hi = M+1;
    while (lo < hi) {
        int mid = lo + hi >> 1;
        if (chk(mid)) hi = mid;
        else lo = mid+1;
    }
    printf("%d\n", hi>M?-1:hi);
    return 0;
}