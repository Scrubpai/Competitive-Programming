#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))

int n, a[105][105];

void solve(int tc) {

    cin >> n; ms(a, 0);
    if (n == 2) { cout << 1 << " " << 1 << nl << 1 << " " << 1 << nl; return; }
    for (int i = 1; i < n; i += 2) a[i][i] = a[i+1][i] = a[i][i+1] = a[i+1][i+1] = 1;
    if (n % 2 == 1) {
        a[n][n] = a[n][1] = a[1][n] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}