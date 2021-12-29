#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
#define nl '\n'
int n, m, e, h[MM];
void solve(int tc) {
    cin >> n >> m >> e >> h[1];
    for (int i=2; i<=n; i++) {
        cin >> h[i];
        if (h[i] - h[i-1] > m) {
            if (e == 0 || h[i] - h[i-1] > 2*m) {
                cout << "Unfair!" << nl;
                return;
            }
            e--;
        }
    }
    cout << "Too easy!" << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }