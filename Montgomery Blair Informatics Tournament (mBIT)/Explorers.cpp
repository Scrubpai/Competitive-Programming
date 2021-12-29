#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int n, m, cnt, a[1005][1005], ans; vector<int> vec;

void solve(int tc) {

    cin >> n >> m;
    for (int i = n; i >= 1; i--) {
        if (i % 2 == n % 2) {
            for (int j = m; j >= 1; j--) a[i][j] = ++cnt;
        } else {
            for (int j = 1; j <= m; j++) a[i][j] = ++cnt;
        }
    }
    cnt = 0;
    for (int j = 1; j <= m; j++) {
        if (j % 2 == 1) {
            for (int i = 1; i <= n; i++) {
                if (a[i][j] == ++cnt) ans++, vec.push_back(cnt);
            }
        } else {
            for (int i = n; i >= 1; i--) {
                if (a[i][j] == ++cnt) ans++, vec.push_back(cnt);
            }
        }
    }
    cout << ans << nl;
    for (int x : vec) cout << x << ' ';

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}