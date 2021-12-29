#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
typedef long long ll;
int n, r[MM], c[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i=0; i<n; i++) cin >> c[i];
    for (int i=0; i<n; i++) cin >> r[i];
    sort(c, c+n); sort(r, r+n);
    if (r[n-1] != c[n-1]) { cout << -1 << '\n'; return 0; }
    ll ans = 0;
    for (int i=0, j=0; i<n; i++) {
        while (j<n && c[j]<r[i]) ans += 1ll*(n-i)*c[j], j++;
        ans += (1ll)*(n-j)*r[i];
    }
    cout << ans << '\n';
}