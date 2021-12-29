#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5 + 5, MX = 1e4 + 5;
#define nl '\n'
auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);
int n, k; ll w[MM]; bool p[MM]; vector<int> primes; map<ll, int> mp;
void sieve() {
    for (ll i = 2; i <= 1e5; i++) {
        if (!p[i]) {
            for (ll j = i*i; j <= 1e5 ; j+=i) p[j] = 1;
            primes.push_back(i);
            w[i] = rng();
        }
    }
}
void solve(int tc) {
    cin >> n >> k;
    sieve();
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        ll hsh = 0, hsh2 = 0;
        for (int v : primes) {
            if (v > x || v > sqrt(x)) break;
            if (x % v == 0) {
                int cnt = 0;
                while (x % v == 0) x /= v, cnt++;
                cnt %= k;
                hsh += 1ll*cnt*w[v];
                cnt = (k-cnt)%k;
                hsh2 += 1ll*cnt*w[v];
            }
        }
        if (x > 1) { hsh += w[x]; hsh2 += 1ll*(k-1)*w[x]; }
        ans += mp[hsh2];
        mp[hsh]++;
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}