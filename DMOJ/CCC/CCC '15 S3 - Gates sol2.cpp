#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
#define nl '\n'
int g, p, dsu[MM];
int fd(int u) {
    if (dsu[u] != u) dsu[u] = fd(dsu[u]);
    return dsu[u];
}
void solve(int tc) {
    cin >> g >> p;
    for (int i=1; i<=g; i++) dsu[i] = i;
    for (int i=0, n; i<p; i++) {
        cin >> n;
        int fu = fd(n), fv = fd(fu-1);
        if (fu == 0) { cout << i << nl; return; }
        else dsu[fu] = fv;
    }
    cout << p << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }