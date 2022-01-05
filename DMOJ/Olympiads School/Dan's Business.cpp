#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+5;
#define nl '\n'
int N, M, a[MM], v[MM], s[MM], t[MM];
bool chk(int x) {
    vector<ll> dif(N+2);
    for (int i=1; i<=x; i++) dif[s[i]] += v[i], dif[t[i]+1] -= v[i];
    for (int i=1; i<=N; i++) {
        dif[i] += dif[i-1];
        if (dif[i] > a[i]) return false;
    }
    return true;
}
void solve(int tc) {
    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> a[i];
    for (int i=1; i<=M; i++) cin >> v[i] >> s[i] >> t[i];
    int lo = 1, hi = M, ans = M+1;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (chk(mid)) lo = mid+1;
        else ans = mid, hi = mid - 1;
    }
    if (ans > M) cout << 0 << nl;
    else cout << -1 << nl << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }