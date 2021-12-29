#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N, a[1005], b[1005];
void solve(int tc) {
    cin >> N;
    int ans = 1e9;
    for (int i=1; i<=N; i++) {
        cin >> a[i] >> b[i];
        ans = min(ans, a[i]+b[i]);
        for (int j=i-1; j>=1; j--) ans = min({ans, max(a[i], b[j]), max(a[j], b[i])});
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }