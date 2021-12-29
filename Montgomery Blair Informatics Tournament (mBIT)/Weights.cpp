#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MM = 1e5 + 5;
int n, a[MM]; ll pre[MM], suf[MM]; double ans;

void solve (int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) pre[i] = pre[i-1] + a[i];
    for (int i = n; i >= 1; i--) suf[i] = suf[i+1] + a[i];
    for (int i = 1; i < n; i++) {
        ans = max(ans, 1.0*abs(1.0*pre[i]/i - 1.0*suf[i+1]/(n-i)));
    }
    cout << setprecision(100) << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}