#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> a(n, vector<int>(n)), vis(n, vector<int>(n));
        auto cnt = [&](int x, int y) {
            int ret = 0;
            if (x>0) ret ^= vis[x-1][y];
            if (x<n-1) ret ^= vis[x+1][y];
            if (y>0) ret ^= vis[x][y-1];
            if (y<n-1) ret ^= vis[x][y+1];
            return ret;
        };
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin >> a[i][j];
            }
        }
        for (int i=1; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (!cnt(i-1, j)) {
                    vis[i][j] = 1;
                    ans ^= a[i][j];
                }
            }
        }
        cout << ans << '\n';
    }
}