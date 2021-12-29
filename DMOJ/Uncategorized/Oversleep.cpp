#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int r, c, r0, c0, r1, c1, dis[1005][1005], dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; char g[1005][1005]; queue<pii> q;
int main() {
//    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    scanf("%d %d", &r, &c);
    for (int i=0; i<r; i++) {
        scanf("%s", g[i]);
        for (int j=0; j<c; j++) {
            if (g[i][j] == 's') r0 = i, c0 = j;
            else if (g[i][j] == 'e') r1 = i, c1 = j;
        }
    }
    q.push({r0, c0}); memset(dis, -1, sizeof(dis)); dis[r0][c0] = 0;
    while (!q.empty()) {
        int cr = q.front().first, cc = q.front().second; q.pop();
        for (int k=0; k<4; k++) {
            int nr = cr + dir[k][0], nc = cc + dir[k][1];
            if (nr>=0 && nr<r && nc>=0 && nc<c && dis[nr][nc]<0 && g[nr][nc]!='X') {
                dis[nr][nc] = dis[cr][cc] + 1;
                q.push({nr, nc});
            }
        }
    }
    printf("%d\n", dis[r1][c1]<0?-1:dis[r1][c1]-1);
    return 0;
}