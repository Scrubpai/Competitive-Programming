#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
ll N, mx=999, mn=1, ans;
void solve(int tc) {
    cin >> N;
    for (int i=1; i<=5; i++) {
        mx = mx*1000 + 999;
        mn *= 1000;
        ans += 1ll*i*max(min(mx, N) - mn + 1, 0ll);
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }