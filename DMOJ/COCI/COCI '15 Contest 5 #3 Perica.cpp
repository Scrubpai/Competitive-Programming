#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5, mod = 1e9+7;
#define nl '\n'
int N, K, a[MM]; ll f[MM], inv[MM], ans;
ll qpow(ll x, ll exp) {
    ll ret = 1;
    for (; exp; exp>>=1) {
        if (exp & 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
    }
    return ret;
}
ll c(int n, int k) { return f[n] * inv[k] % mod * inv[n-k] % mod; }
void solve(int tc) {
    cin >> N >> K;
    for (int i=0; i<N; i++) cin >> a[i];
    sort(a, a+N);
    f[0] = inv[0] = 1;
    for (int i=1; i<=N; i++) {
        f[i] = f[i-1] * i % mod;
        inv[i] = qpow(f[i], mod - 2);
    }
    for (int i=K-1; i<N; i++) ans += 1ll * a[i] * c(i, K-1) % mod, ans %= mod;
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }