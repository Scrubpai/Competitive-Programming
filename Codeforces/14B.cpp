#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define INF 0x3f3f3f3f

int n, x0, cnt[1005];

void solve (int tc) {

    cin >> n >> x0;
    for (int i = 1, a, b; i <= n; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        for (int j = a; j <= b; j++) {
            cnt[j]++;
        }
    }
    int ans = INF;
    for (int i = 0; i <= 1000; i++) {
        if (cnt[i] == n) {
            ans = min(ans, abs(i - x0));
        }
    }
    if (ans == INF) cout << -1 << nl;
    else cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}