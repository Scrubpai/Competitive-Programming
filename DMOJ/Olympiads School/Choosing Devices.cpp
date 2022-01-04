#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5, mod = 1e9+7;
#define nl '\n'
int N, D, a[MM+1], freq[MM+1]; ll f[MM+1], inv[MM+1];
ll qpow(ll b, ll exp) {
    ll ret = 1;
    for (; exp; exp>>=1) {
        if (exp & 1) ret = (ret * b) % mod;
        b = (b * b) % mod;
    }
    return ret;
}
void init() {
    f[0] = 1; inv[0] = 1;
    for (int i=1; i<=MM; i++) f[i] = f[i-1] * i % mod;
    for (int i=1; i<=MM; i++) inv[i] = qpow(f[i], mod-2);
}
ll c(int n, int k) {
    return f[n] * inv[k] % mod * inv[n-k] % mod;
}
void solve(int tc) {
    cin >> N; init();
    for (int i=1; i<=N; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    sort(a+1, a+1+N);
    for (int i=1; i<=N; i++) freq[i] += freq[i-1];
    cin >> D;
    for (int i=1, k; i<=D; i++) {
        cin >> k;
        int cost = a[k], need = k - freq[cost-1], tot = freq[cost] - freq[cost-1];
        cout << c(tot, need) << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }