#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MM = 1e5+5;
int N, M, f[MM], dsu[MM]; ll ans;
int fd(int x) { if (dsu[x] == x) return x; else return dsu[x] = fd(dsu[x]); }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for (int i=1; i<=N; i++) { cin >> f[i]; dsu[i] = i; }
    for (int i=1, x, y; i<=M; i++)  {
        cin >> x >> y;
        int fx = fd(x), fy = fd(y);
        if (fx != fy) dsu[fx] = fy;
    }
    vector<pii> edges;
    for (int i=2; i<=N; i++) edges.push_back({f[i] - f[i-1], {i-1, i}});
    sort(edges.begin(), edges.end());
    for (int i=0, c, u, v; i<(int)edges.size(); i++) {
        c = edges[i].first; tie(u, v) = edges[i].second;
        int fu = fd(u), fv = fd(v);
        if (fu != fv) ans += c, dsu[fu] = fv;
    }
    cout << ans << '\n';
}