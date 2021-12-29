#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int n, m, r1 = 51, c1 = 51, r2, c2; char grid[51][51];

void solve (int tc) {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '*') {
                r1 = min(r1, i);
                c1 = min(c1, j);
                r2 = max(r2, i);
                c2 = max(c2, j);
            }
        }
    }
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            cout << grid[i][j];
        }
        cout << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}