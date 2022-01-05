#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+5;
#define nl '\n'
int N, mx, psa[MM], cnt[MM]; ll ans;
void solve(int tc) {
    cin >> N;
    for (int i=1, a; i<=N; i++) { cin >> a; psa[a]++; mx = max(mx, a); }
    for (int i=1; i<=mx; i++) psa[i] += psa[i-1];
    for (int x=1; x<=mx; x++) {
        int odd = 0, val = -1;
        for (int t=x; t<=mx; t+=x) {
            cnt[t/x] = psa[min(mx, t+x-1)] - psa[t-1];
            if (cnt[t/x] & 1) odd++, val = t/x;
        }
        if (val == -1) continue;
        if ((odd == 1 && (cnt[1]&1)) || (odd == 2 && val > 1 && (cnt[val-1]&1))) ans += cnt[val];
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }