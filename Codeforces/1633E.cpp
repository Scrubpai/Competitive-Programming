#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e7+5;
struct E { int u, v, w, x; } edges[301];
int n, m, p, k, dsu[51]; vector<int> adj[301*301]; ll a, b, c, q[MM];
int fd(int p) { if (dsu[p] == p) return p; else return dsu[p] = fd(dsu[p]); }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i=1; i<=m; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
    vector<int> swaps; swaps.push_back(0);
    for (int i=1; i<=m; i++) {
        for (int j=i+1; j<=m; j++) {
            int w1 = min(edges[i].w, edges[j].w), w2 = max(edges[i].w, edges[j].w);
            swaps.push_back((w1+w2)/2+1);
        }
    }
    sort(swaps.begin(), swaps.end()); swaps.resize(unique(swaps.begin(), swaps.end()) - swaps.begin());
    for (int i=0; i<(int)swaps.size(); i++) {
        for (int j=1; j<=n; j++) dsu[j] = j;
        for (int j=1; j<=m; j++) edges[j].x = swaps[i];
        sort(edges+1, edges+1+m, [](E a, E b) { return abs(a.w-a.x) < abs(b.w-b.x); });
        for (int j=1; j<=m; j++) {
            int fu = fd(edges[j].u), fv = fd(edges[j].v);
            if (fu != fv) dsu[fu] = fv, adj[i].push_back(edges[j].w);
        }
    }
    cin >> p >> k >> a >> b >> c;
    ll ans = 0;
    for (int i=1; i<=k; i++) {
        if (i<=p) cin >> q[i];
        else q[i] = (q[i-1] * a + b) % c;
        int lo = 0, hi = (int)swaps.size()-1, idx = -1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (q[i] >= swaps[mid]) idx = max(idx, mid), lo = mid+1;
            else hi = mid-1;
        }
        ll cur = 0;
        for (int j=0; j<n-1; j++) cur += abs(adj[idx][j]-q[i]);
        ans ^= cur;
    }
    cout << ans << '\n';
}