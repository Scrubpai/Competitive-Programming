#include <bits/stdc++.h>
using namespace std;
const int MM = 5e4+5;
#define nl '\n'
int N, K, dsu[3*MM];
int fd(int u) {
    if (dsu[u] != u) dsu[u] =  fd(dsu[u]);
    return dsu[u];
}
bool chk(int x, int y) {
    return fd(x) == fd(y);
}
void unite(int x, int y) {
    int fx = fd(x), fy = fd(y);
    if (fx != fy) dsu[fx] = fy;
}
void solve(int tc) {
    cin >> N >> K;
    int ans = 0;
    for (int i=1; i<=3*N; i++) dsu[i] = i;
    for (int i=1, d, x, y; i<=K; i++) {
        cin >> d >> x >> y;
        if (x > N || y > N) { ans++; continue; }
        if (d == 1) {
            if (chk(x, y+N) || chk(x, y+2*N)) ans++;
            else unite(x, y), unite(x+N, y+N), unite(x+2*N, y+2*N);
        } else {
            if (chk(x, y) || chk(y, x+N)) ans++;
            else unite(x, y+N), unite(x+N, y+2*N), unite(x+2*N, y);
        }
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }