#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6 + 5;
#define nl '\n'
#define INF 0x3f3f3f3f
int n, m, p[MM], dis[105][105], v[MM]; char c;
void solve(int tc) {
    cin >> n;
    memset(dis, INF, sizeof(dis));
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
        for (int j = 1; j <= n; j++) {
            cin >> c;
            if (c == '1') dis[i][j] = 1;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> p[i];
    int ans = 1, last = 1; v[1] = p[1];
    for (int i = 2; i <= m; i++) {
        if (dis[p[last]][p[i]] < i - last) {
            v[++ans] = p[i-1];
            last = i-1;
        }
    }
    v[++ans] = p[m];
    cout << ans << nl;
    for (int i = 1; i <= ans; i++) cout << v[i] << ' ';
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}