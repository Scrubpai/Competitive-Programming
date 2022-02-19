#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
struct E { int u, v, w; };
int N, M, dsu[MM], t[MM]; ll ans, lvl=1;
int fd(int x) { if (dsu[x] == x) return x; else return dsu[x] = fd(dsu[x]); }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M; vector<E> edges(M);
    for (int i=1; i<=N; i++) { dsu[i] = i; cin >> t[i]; }
    for (int i=0; i<M; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
    sort(edges.begin(), edges.end(), [&](E &a, E &b) { return a.w < b.w; });
    for (E &e : edges) {
        int fu = fd(e.u), fv = fd(e.v), w = e.w;
        ans += (w - lvl) * t[fd(1)]; lvl = w;
        if (fu != fv) dsu[fu] = fv, t[fv] = min(t[fv], t[fu]);
        if (fd(1) == fd(N)) { cout << ans << '\n'; return 0; }
    }
    cout << -1 << '\n';
}