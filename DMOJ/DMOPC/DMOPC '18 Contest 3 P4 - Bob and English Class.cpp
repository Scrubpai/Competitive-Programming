#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 2e5+5;
int K, N, cnt[MM], sz[MM], dis[MM]; ll ans; vector<pii> adj[MM];
void dfs(int u, int pa) {
    sz[u] = cnt[u];
    for (pii p: adj[u]) {
        int v = p.first, d = p.second;
        if (v == pa) continue;
        dis[v] = dis[u] + d; dfs(v, u); sz[u] += sz[v];
    }
}
int getCenter(int u, int pa) {
    for (pii p: adj[u]) {
        int v = p.first;
        if (v == pa) continue;
        if (2 * sz[v] > K) return getCenter(v, u);
    }
    return u;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> K >> N;
    for (int i=1, z; i<=K; i++) { cin >> z; cnt[z]++; }
    for (int i=1, a, b, d; i<N; i++) {
        cin >> a >> b >> d;
        adj[a].push_back({b, d}); adj[b].push_back({a, d});
    }
    dfs(1, 0); memset(dis, 0, sizeof(dis)); dfs(getCenter(1, 0), 0);
    for (int i=1; i<=N; i++) ans += 1ll*cnt[i]*dis[i];
    cout << ans << '\n';
}