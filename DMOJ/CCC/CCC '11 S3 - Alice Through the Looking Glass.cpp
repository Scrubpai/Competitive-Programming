#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int T, vis[6][6];
void solve(int tc) {
    cin >> T; vis[1][0] = vis[2][0] = vis[3][0] = vis[2][1] = 1;
    vis[1][1] = vis[2][2] = vis[3][1] = -1;
    while (T--) {
        int m, x, y; cin >> m >> x >> y; int tmpx = x, tmpy = y;
        for (int i = m; i >= 1; i--) {
            int mag = pow(5, i - 1); tmpx = x / mag; tmpy = y / mag;
            if (vis[tmpx][tmpy] == 1) { cout << "crystal" << nl; break; }
            else if (vis[tmpx][tmpy] == 0) { cout << "empty" << nl; break; }
            else {
                if (i == 1) cout << "empty" << nl;
                else { x %= mag; y %= mag; }
            }
        }
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }