#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))

int n, t; ll dp[25][15][15][6][6];

ll fun(int i, int h, int u, int y1, int y2) {
    //ith vertex, h humps left, u other humps left, y1 is y[i+1]th height, y2 is y[i+2]th height
    if (i == 0) {
        if (h == 0 && u == 0) return 1;
        else return 0;
    }
    if (dp[i][h][u][y1][y2] != -1) return dp[i][h][u][y1][y2];
    ll ret = 0;
    for (int y = 1; y <= 4; y++) {
        if (y == y1) continue;
        if (y1 > y2 && y1 > y && y1 != 5 && y2 != 5) ret += fun(i - 1, h - 1, u, y, y1);
        else if (y1 < y2 && y1 < y && y1 != 5 && y2 != 5) ret += fun(i - 1, h, u - 1, y, y1);
        else ret += fun(i - 1, h, u, y, y1);
    }
    return dp[i][h][u][y1][y2] = ret;
}

void solve(int tc) {

    cin >> n >> t; ms(dp, -1);
    cout << fun(n, t, t - 1, 5, 5) << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}