#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
int n, m, a[MM];
bool chk(ll s) {
    int cnt = 0; ll cur = 0;
    for (int i=1; i<=n; i++) {
        cur += a[i];
        if (cur > s) cnt++, cur = a[i];
    }
    return cnt+1<=m;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    ll lo = 0, hi = 1e14;
    for (int i=1; i<=n; i++) { cin >> a[i]; lo = max(lo, 1ll*a[i]); }
    while (lo < hi) {
        ll mid = lo+hi>>1ll;
        if (chk(mid)) hi = mid;
        else lo = mid+1;
    }
    printf("%lld\n", hi);
    return 0;
}