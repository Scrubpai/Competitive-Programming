#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 1e5+5;
int N, M, L, pre[MM], far; ll dis[MM], maxd; vector<pi> adj[MM];
void dfs(int u, int pa, ll d) {
    pre[u] = pa; dis[u] = d;
    if (d > maxd) maxd = d, far = u;
    for (auto &[v, t]: adj[u])
        if (v != pa) dfs(v, u, d+t);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M >> L;
    for (int i=0, A, B, T; i<M; i++) {
        cin >> A >> B >> T;
        adj[A].push_back({B, T});
        adj[B].push_back({A, T});
    }
    memset(dis, -1, sizeof(dis));
    ll maxdia = 0, maxrad = 0; vector<ll> v;
    for (int i=0; i<N; i++) {
        ll rad = 1e18;
        if (dis[i] == -1) {
            maxd = -1; dfs(i, -1, 0);
            maxd = -1; dfs(far, -1, 0);
            for (int j=far; j!=-1; j=pre[j]) rad = min(rad, max(dis[j], maxd - dis[j]));
            if (rad > maxrad) v.push_back(maxrad), maxrad = rad;
            else v.push_back(rad);
            maxdia = max(maxdia, maxd);
        }
    }
    sort(v.begin(), v.end());
    ll ans = maxdia;
    if (v.size() >= 2) ans = max(ans, v.back() + L + maxrad);
    if (v.size() >= 3) ans = max(ans, v[v.size()-1] + v[v.size()-2] + 2*L);
    cout << ans << '\n';
}