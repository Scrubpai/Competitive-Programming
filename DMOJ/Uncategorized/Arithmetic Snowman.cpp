#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+1;
#define nl '\n'
int n, a[3005], freq[MM];
void solve(int tc) {
    cin >> n;
    for (int i=0; i<n; i++) { cin >> a[i]; freq[a[i]]++; }
    sort(a, a+n);
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int k = 2 * a[j] - a[i];
            if (k >= MM) continue;
            if ((a[i] != a[j] && freq[k]) || (a[i] == a[j] && freq[k] >= 3)) {
                ans = max(ans, 3*a[j]);
            }
        }
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }