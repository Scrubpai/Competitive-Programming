#include <bits/stdc++.h>
using namespace std;
const int MM = 2.5e4+4;
#define nl '\n'
void solve(int tc) {
    int N, ans; cin >> N; ans = N; vector<int> dp(MM), a(N);
    for (int i=0; i<N; i++) cin >> a[i];
    sort(a.begin(), a.end()); dp[0] = 1;
    for (int i=0; i<N; i++) {
        if (dp[a[i]]) { ans--; continue; }
        for (int j=a[i]; j<=a[N-1]; j++) dp[j] = dp[j] | dp[j-a[i]];
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }