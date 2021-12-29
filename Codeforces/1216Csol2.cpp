#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
inline bool ok(int x, int y, int x1, int y1, int x2, int y2) {
    return x < x1 || x2 < x || y < y1 || y2 < y;
}
void solve(int tc) {
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
    x1 *= 2, y1 *= 2; x2 *= 2, y2 *= 2; x3 *= 2, y3 *= 2; x4 *= 2, y4 *= 2; x5 *= 2, y5 *= 2; x6 *= 2, y6 *= 2;
    for (int x = x1; x <= x2; x++) {
        if (ok(x, y1, x3, y3, x4, y4) && ok(x, y1, x5, y5, x6, y6)) {
            cout << "YES" << endl;
            return;
        }
        if (ok(x, y2, x3, y3, x4, y4) && ok(x, y2, x5, y5, x6, y6)) {
            cout << "YES" << endl;
            return;
        }
    }
    for (int y = y1; y <= y2; y++) {
        if (ok(x1, y, x3, y3, x4, y4) && ok(x1, y, x5, y5, x6, y6)) {
            cout << "YES" << endl;
            return;
        }
        if (ok(x2, y, x3, y3, x4, y4) && ok(x2, y, x5, y5, x6, y6)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int32_t main() {
    //freopen("billboard.in", "r", stdin); freopen("billboard.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}