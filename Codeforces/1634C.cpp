#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k, a=-1, b=0; cin >> n >> k;
        vector<vector<int>> ans(n+1, vector<int>(k+1));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=k; j++) {
                if (i&1) {
                    a+=2;
                    ans[i][j] = a;
                } else {
                    b+=2;
                    ans[i][j] = b;
                }
            }
        }
        if (a>n*k || b>n*k) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=k; j++) {
                    cout << ans[i][j] << ' ';
                }
                cout << '\n';
            }
        }
    }
}