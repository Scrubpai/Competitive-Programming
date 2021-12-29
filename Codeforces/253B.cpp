#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
#define nl '\n'
int n, c[MM];
int32_t main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    sort(c + 1, c + 1 + n);
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        //remove the first i measurements
        int idx = upper_bound(c + 1, c + 1 + n, 2*c[i+1]) - (c + 1) + 1;
        ans = min(ans, i + n - idx + 1);
    }
    cout << ans << nl;
    // int tc = 1;// cin >> tc;
    // for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}