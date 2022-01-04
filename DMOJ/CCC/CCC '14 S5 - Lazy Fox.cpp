#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define INF 0x3f3f3f3f
struct E { int a, b, d; };
bool cmp(E a, E b) { return a.d > b.d; }
int N, x[2005], y[2005], dp[2005], dist[2005], tmp[2005]; vector<E> edges;
void solve(int tc) {
    cin >> N;
    memset(dp, -INF, sizeof(dp)); memset(dist, INF, sizeof(dist)); dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> x[i] >> y[i];
        edges.push_back({0, i, x[i]*x[i]+y[i]*y[i]});
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            edges.push_back({i, j, (x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i])});
        }
    }
    sort(edges.begin(), edges.end(), cmp);
    int ans = 0, sz = edges.size();
    for (int i = 0; i < sz; i++) {
        int u = edges[i].a, v = edges[i].b;
        if (dist[u] != edges[i].d) tmp[u] = dp[u], dist[u] = edges[i].d;
        if (dist[v] != edges[i].d) tmp[v] = dp[v], dist[v] = edges[i].d;
        if (v != 0) dp[v] = max(dp[v], tmp[u] + 1);
        if (u != 0) dp[u] = max(dp[u], tmp[v] + 1);
        ans = max({ans, dp[u], dp[v]});
    }
    cout << ans << nl;
}
int32_t main() {
    //freopen("", "r", stdin); freopen("", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}