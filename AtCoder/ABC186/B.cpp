#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int H, W, mn = 1e9, a[105][105];
void solve(int tc) {
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> a[i][j];
            mn = min(mn, a[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            ans += a[i][j] - mn;
        }
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}