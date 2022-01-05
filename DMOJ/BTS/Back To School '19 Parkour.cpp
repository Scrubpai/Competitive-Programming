#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int X, Y, H, V, T;

void solve(int tc) {

    cin >> X >> Y >> H >> V >> T;
    for (int i = 0; i < T; i++) {
        int x = i, y = 2 * i, t = max({(X - x) / 2, Y - y, 0});
        if (i + t >= T) continue;
        if (x + 2 * t >= X && x + 2 * t < X + H && y + t >= Y && y + t <= Y + V) {
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}