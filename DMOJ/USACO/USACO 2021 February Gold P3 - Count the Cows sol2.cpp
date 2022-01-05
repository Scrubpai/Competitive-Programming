#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
int xd[40], yd[40], dd[40]; ll dp[40][2][2][2]; //stores base 3 digits
void init(ll x, ll y, ll d) {
    memset(dp, -1, sizeof(dp));
    for (int p=0; p<40; p++, x/=3, y/=3, d/=3) xd[p] = x%3, yd[p] = y%3, dd[p] = d%3;
}
bool chk(int a, int b) {
    if (a < 0 || b < 0 || a > 2 || b > 2) return false;
    return (a&1)==(b&1);
}
ll fun(int pos, int lmt, int xc, int yc) { //[pos][max digit][carry value for x][carry value for y]
    if (pos < 0) return (xc == 0 && yc == 0);
    ll &ret = dp[pos][lmt][xc][yc];
    if (ret != -1) return ret;
    ret = 0;
    int mx = lmt?dd[pos]:2;
    for (int i=0; i<=mx; i++) {
        for (int j=0; j<=1; j++) {
            for (int k=0; k<=1; k++) {
                if (chk(i+xd[pos]-3*xc+j, i+yd[pos]-3*yc+k)) {
                    ret += fun(pos-1, lmt && i==dd[pos], j, k);
                }
            }
        }
    }
    return ret;
}
void solve(int tc) {
    int Q; cin >> Q;
    while (Q--) {
        ll d, x, y; cin >> d >> x >> y;
        init(x, y, d);
        cout << fun(39, 1, 0, 0) << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }