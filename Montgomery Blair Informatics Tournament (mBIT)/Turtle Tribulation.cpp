#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define nl '\n'
#define INF 0x3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))

int n, z; double k; pii pts[2505]; ll dp[2505][2505];

void solve(int tc) {

    cin >> n >> z >> k; ms(dp, INF);
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        pts[i] = {y, x};
    }
    sort(pts + 1, pts + 1 + n);
    dp[1][pts[1].second] = 0;
    for (int i = 2; i <= n; i++) {
        int y1 = pts[i-1].first, x2 = pts[i].second, y2 = pts[i].first, val = (int)((1.0 * y2 - y1) / k);
        deque<int> dq;
        for (int j = 1, l = 1; j <= z; j++) {
            while (l <= min(j + val, z)) {
                while (!dq.empty() && dp[i-1][dq.back()] > dp[i-1][l]) dq.pop_back();
                dq.push_back(l); l++;
            }
            if (dq.front() == j - val - 1) dq.pop_front();
            dp[i][j] = min(dp[i-1][dq.front()] + abs(j - x2), 1ll*INF);
        }
    }
    cout << dp[n][pts[n].second] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}