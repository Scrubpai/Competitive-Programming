#include <bits/stdc++.h>
using namespace std;
const int MM = 1002;
#define nl '\n'
int n, a[MM][MM], row[MM], col[MM]; char c;
void solve(int tc) {
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> c;
            a[i][j] = (c == 'R');
        }
    }
    for (int j=1; j<=n; j++) {
        if (a[1][j]) {
            for (int i=1; i<=n; i++) {
                a[i][j] ^= 1;
            }
        }
    }
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (a[i][1]) {
            for (int j=1; j<=n; j++) {
                a[i][j] ^= 1;
            }
        }
        for (int j=1; j<=n; j++) {
            if (a[i][j]) cnt++, row[i]++, col[j]++;
        }
    }
    if (cnt == 1) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (a[i][j]) { cout << i << " " << j << nl; return; }
            }
        }
    } else if (cnt == (n-1)*(n-1)) {
        cout << 1 << " " << 1 << nl; return;
    } else if (cnt == n-1) {
        for (int i=2; i<=n; i++) {
            if (row[i] == n-1) { cout << i << " " << 1 << nl; return; }
            if (col[i] == n-1) { cout << 1 << " " << i << nl; return; }
        }
    } else {
        cout << -1 << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }