#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3e5+5;
#define nl '\n'
int N, x; ll a[MM], pre[MM], suf[MM], psa[MM], ans;
void solve(int tc) {
    cin >> N >> x;
    for (int i=1; i<=N; i++) {
        cin >> a[i];
        psa[i] = psa[i-1] + a[i];
        pre[i] = max({0ll, pre[i-1]+a[i], a[i]});
        ans = max(ans, pre[i]);
    }
    for (int i=N; i>=1; i--) suf[i] = max({0ll, suf[i+1]+a[i], a[i]});
    ll best = 0;
    for (int i=1; i<=N; i++) {
        ans = max(ans, suf[i+1]+x*psa[i]+best);
        best = max(best, pre[i]-x*psa[i]);
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }