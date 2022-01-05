#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
int Q; ll p[40], f[40];
void init(int k, ll dif) { //f[k]: # of cows (x, y) in any X-square [0, 3^k) x [0, 3^k) and x-y=dif
    dif = abs(dif);
    if (k == 0) { f[k] = (dif == 0); return; }
    if (dif < p[k-1]) { init(k-1, dif); f[k] = 3*f[k-1]; }
    else { init(k-1, dif-2*p[k-1]); f[k] = f[k-1]; }
}
ll rec(ll x, ll y, int k) { //count # cows in any X-square [0, 3^k) x [0, 3^k) in the diagonal up to (x, y)
    x %= p[k]; y %= p[k];
    if (k == 0) return 1;
    if (x < y) swap(x, y);
    ll dif = x - y;
    if (dif >= p[k-1]) {
        if (x < 2*p[k-1]) return 0;
        if (y < p[k-1]) return rec(x, y, k-1);
        if (y >= p[k-1]) return f[k-1];
    }
    if (x < p[k-1]) return rec(x, y, k-1);
    if (y < p[k-1]) return f[k-1];
    if (x < 2*p[k-1]) return f[k-1] + rec(x, y, k-1);
    if (y < 2*p[k-1]) return 2*f[k-1];
    return 2*f[k-1] + rec(x, y, k-1);
}
ll query(ll x, ll y) {
    if (x < 0 || y < 0) return 0;
    return rec(x, y, 39);
}
void solve(int tc) {
    p[0] = 1;
    for (int i=1; i<40; i++) p[i] = p[i-1] * 3;
    cin >> Q;
    while (Q--) {
        ll d, x, y; cin >> d >> x >> y;
        init(39, x-y);
        cout << query(x+d, y+d) - query(x-1, y-1) << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }