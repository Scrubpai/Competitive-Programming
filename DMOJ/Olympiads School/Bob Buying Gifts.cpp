#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N, T;
void solve(int tc) {
    cin >> N >> T;
    int ans = 0;
    for (int i = 1, c, v; i <= N; i++) {
        cin >> c >> v;
        if (c <= T) ans = max(ans, v);
    }
    cout << ans << nl;
}
int32_t main() {
    //freopen("", "r", stdin); freopen("", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}