#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
int t;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    while (t--) {
        int n; ll mn=1e9+1, cnt=0; ll k; cin >> n >> k; vector<ll> a(n); ll sum = 0;
        vector<ll> pre(n+1,0);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            sum += a[i];
            if (a[i] < mn) mn = a[i], cnt = 1;
            else if (a[i] == mn) cnt++;
        }
        sort(a.begin(), a.end());
        for (int i=0; i<n; i++) {
            pre[i+1] = pre[i] + a[i];
        }
        if (sum <= k) { cout << 0 << '\n'; continue; }
        if (n == 1) { cout << sum-k << '\n'; continue; }
        ll ans = 1e18;
        for (int i=n; i>0; i--) {
            ll x = floor(1.0*(k-pre[i]+a[0])/(n-i+1));
            ans = min(ans, max(a[0]-x, 0ll)+(n-i));
        }
        cout << ans << "\n";
    }
}