#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
#define nl '\n'
struct edge { int u, v, c, t; };
int N, M, P, Q, cities[MM], planets[MM]; vector<edge> edges;
int fd(int d, int p[]) {
    if (d != p[d]) p[d] = fd(p[d], p);
    return p[d];
}
void solve(int tc) {
    cin >> N >> M >> P >> Q;
    for (int i=1; i<=N; i++) planets[i] = i;
    for (int i=1; i<=M; i++) cities[i] = i;
    ll tot = 0;
    for (int i=1, a, b, c; i<=P; i++) {
        cin >> a >> b >> c;
        edges.push_back({a, b, c, 0});
        tot += 1ll*N*c;
    }
    for (int i=1, x, y, z; i<=Q; i++) {
        cin >> x >> y >> z;
        edges.push_back({x, y, z, 1});
        tot += 1ll*M*z;
    }
    sort(edges.begin(), edges.end(), [](edge a, edge b) { return a.c < b.c; });
    ll mst = 0;
    for (edge e : edges) {
        if (e.t == 0) { //flight (horiz), M cities, reduce cities to use portals on
            int fu = fd(e.u, cities), fv = fd(e.v, cities);
            if (fu != fv) {
                cities[fu] = fv;
                mst += 1ll * N * e.c;
                M--;
            }
        } else { //portal (vert), N planets, reduce planets to use flights on
            int fu = fd(e.u, planets), fv = fd(e.v, planets);
            if (fu != fv) {
                planets[fu] = fv;
                mst += 1ll * M * e.c;
                N--;
            }
        }
    }
    cout << tot - mst << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }