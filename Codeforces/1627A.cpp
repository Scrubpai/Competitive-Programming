#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, m, r, c; cin >> n >> m >> r >> c; vector<vector<char>> g(n, vector<char>(m));
        bool flag1 = 0, flag2 = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> g[i][j];
                if (g[i][j] == 'B') {
                    flag2 = 1;
                    if (i==r-1 || j==c-1) flag1 = 1;
                }
            }
        }
        if (g[r-1][c-1] == 'B') cout << 0 << '\n';
        else if (flag1) cout << 1 << '\n';
        else if (flag2) cout << 2 << '\n';
        else cout << -1 << '\n';
    }
}