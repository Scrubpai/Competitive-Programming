#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int n, m, a[15][15], cnt, zero;

void solve(int tc) {

    cin >> n >> m;
    cnt = 0; zero = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] < 0) cnt++;
            if (a[i][j] == 0) zero++;
        }
    }
    if (cnt % 2 == 0 || (cnt % 2 == 1 && zero)) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ans += abs(a[i][j]);
            }
        }
        cout << ans << nl;
    } else {
        int mx = 105, r = -1, c = -1, ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (abs(a[i][j]) < mx) mx = abs(a[i][j]), r = i, c = j;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == r && j == c) ans += -abs(a[i][j]);
                else ans += abs(a[i][j]);
            }
        }
        cout << ans << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}