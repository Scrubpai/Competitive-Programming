#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
int N; ll ans;
void f(int l, int r, int lval, int rval) {
    if (lval == 0) return;
    if (l == r) { ans += 1ll * lval * l; return; }
    int mid = (l + r) / 2 + 1;
    cout << "? " << mid << endl;
    int ret; cin >> ret;
    f(l, mid - 1, lval - (ret - rval), ret);
    f(mid, r, ret - rval, rval);
}
void solve(int tc) {
    cin >> N;
    f(0, 1e7, N, 0);
    cout << "! " << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}