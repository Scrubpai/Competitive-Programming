#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N, a[105];
void solve(int tc) {
    cin >> N;
    int ans = 1e9;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = -100; i <= 100; i++) {
        int tot = 0;
        for (int j = 1; j <= N; j++) {
            tot += (a[j] - i) * (a[j] - i);
        }
        ans = min(ans, tot);
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}