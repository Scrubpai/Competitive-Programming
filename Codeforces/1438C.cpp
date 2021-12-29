#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int n, m, a[105][105];

void solve(int tc) {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((i + j) % 2 == 0) {
                if (a[i][j] % 2 == 1) a[i][j]++;
            } else {
                if (a[i][j] % 2 == 0) a[i][j]++;
            }
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