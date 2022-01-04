#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))
#define INF 0x3f3f3f3f

int N, dis[1505][1505], dp[1505][1505];

int fun(int l, int r) {
    int nxt = max(l, r) + 1;
    if (nxt > N) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    return dp[l][r] = min(dis[nxt][l] + fun(nxt, r), dis[r][nxt] + fun(l, nxt));
}

void solve(int tc) {

    cin >> N; ms(dp, -1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> dis[i][j];
        }
    }
    cout << fun(1, 1) << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}