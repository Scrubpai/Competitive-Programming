#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
#define nl '\n'
ll n, k, ans[MM];
void solve(int tc) {
    cin >> n >> k;
    ll cur = 0, idx = 0, mx = log2(k);
    for (int i=1; i<=n; i++) {
        if (n-i-1 > mx) { ans[i]=++idx; continue;}
        ll x = (1ll<<(max(n-i-1, 0ll)));
        if (k <= cur + x) {
            if (i==n && k==cur+x) cur+=x;
            ll tmp = idx;
            for (int j=i; j>idx; j--) ans[j]=++tmp;
            idx = tmp;
        } else {
            cur += x;
        }
    }
    if (k!=cur) { cout << -1 << nl; return; }
    for (int i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }