#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5 + 5, mod = 1e9 + 9;
#define nl '\n'
ll n, a, b, k; char c;
ll pwmd(ll b, ll exp) {
    ll ret = 1;
    while (exp > 0) {
        if (exp % 2 == 1) ret = (ret * b) % mod;
        exp /= 2;
        b = (b * b) % mod;
    }
    return ret % mod;
}
void solve(int tc) {
    cin >> n >> a >> b >> k;
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        cin >> c;
        ll tmp = pwmd(b, i) * pwmd(a, n - i) % mod;
        if (c == '+') ans = (ans + tmp) % mod;
        else ans = (ans - tmp + mod) % mod;
    }
    ll m = (n + 1) / k, q = pwmd(b, k) * pwmd(pwmd(a, k), mod - 2) % mod;
    if (q == 1) ans = (ans * m) % mod;
    else ans = (ll)ans * (pwmd(q, m) + mod - 1) % mod * pwmd((q + mod - 1) % mod, mod - 2) % mod;
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}