#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int r, c, row[65], col[65]; char grid[65][65];
void solve(int tc) {
    cin >> r >> c;
    memset(row, 0, sizeof(row)); memset(col, 0, sizeof(col));
    int cnt = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') cnt++, row[i]++, col[j]++;
        }
    }
    if (!cnt) { cout << "MORTAL" << nl; return; }
    if (cnt == r * c) { cout << 0 << nl; return; }
    //ans is now 1, 2, 3, 4
    if (row[1] == c || row[r] == c || col[1] == r || col[c] == r) { cout << 1 << nl; return; }
    if (grid[1][1] == 'A' || grid[1][c] == 'A' || grid[r][1] == 'A' || grid[r][c] == 'A') { cout << 2 << nl; return; }
    for (int i = 2; i < r; i++) {
        if (row[i] == c) {
            cout << 2 << nl;
            return;
        }
    }
    for (int i = 2; i < c; i++) {
        if (col[i] == r) {
            cout << 2 << nl;
            return;
        }
    }
    for (int i = 1; i <= r; i++) {
        if (grid[i][1] == 'A' || grid[i][c] == 'A') {
            cout << 3 << nl;
            return;
        }
    }
    for (int i = 1; i <= c; i++) {
        if (grid[1][i] == 'A' || grid[r][i] == 'A') {
            cout << 3 << nl;
            return;
        }
    }
    cout << 4 << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}