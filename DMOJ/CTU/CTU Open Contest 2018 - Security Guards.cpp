#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define nl '\n'
int N, Q, dis[5005][5005], dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1} };
void solve(int tc) {
    cin >> N >> Q;
    for (int i=0; i<=5000; i++) {
        for (int j=0; j<=5000; j++) {
            dis[i][j] = 1e9;
        }
    }
    queue<pii> q;
    int maxn = 5000;
    for (int i=1, x, y; i<=N; i++) {
        cin >> x >> y;
        q.push({x, y}); dis[x][y] = 0;
    }
    while (!q.empty()) {
        int r = q.front().first, c = q.front().second; q.pop();
        for (int k=0; k<8; k++) {
            int nr = r + dir[k][0], nc = c + dir[k][1];
            if (nr >= 0 && nr <= maxn && nc >= 0 && nc <= maxn && dis[nr][nc] == 1e9) {
                dis[nr][nc] = dis[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    for (int i=0, a, b; i<Q; i++) {
        cin >> a >> b;
        cout << dis[a][b] << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }