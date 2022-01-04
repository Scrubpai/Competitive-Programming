#include <bits/stdc++.h>
using namespace std;
const int MM = 1e7 + 5, mod = 1e9 + 7;
typedef long long ll;
#define nl '\n'
ll N, P, Q, bit[MM], ans[MM], a[MM];
void update(int p, ll v) { for (; p <= N; p += p&-p) bit[p] = (bit[p] + v + mod) % mod; }
ll query(int p) { ll ret = 0; for (; p >= 1; p -= p&-p) ret = (ret + bit[p] + mod) % mod; return ret;}
void solve(int tc) {
    cin >> N >> P >> Q;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int k = N; k >= 1; k--) {
        ll val = 1ll * k * P / Q, rem = (a[N-k+1] + query(N-k+1) + mod) % mod;
        ans[N-k+1] = (ans[N-k] + rem + mod) % mod;
        update(N - k + 1, -rem); update(N - val + 1, 1ll*2*rem);
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << ' ';
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}