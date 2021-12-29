#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
#define f first
#define s second
int N, M, r0, c0, r1, c1, r2, c2, d[2][1005][1005]; char g[1005][1005], dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
void bfs(int r, int c, int dis[][1005]) {
    queue<pi> q; dis[r][c] = 0; q.push({r, c});
    while (!q.empty()) {
        pi cur = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int nr = cur.f + dir[k][0], nc = cur.s + dir[k][1];
            if (g[nr][nc] != '#' && dis[nr][nc] == -1) {
                dis[nr][nc] = dis[cur.f][cur.s] + 1;
                q.push({nr, nc});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'O') r0 = i, c0 = j;
            if (g[i][j] == 'P') r1 = i, c1 = j;
            if (g[i][j] == 'X') r2 = i, c2 = j;
        }
    }
    memset(d, -1, sizeof(d)); bfs(r0, c0, d[0]); bfs(r1, c1, d[1]);
    if (d[0][r1][c1] == -1 || d[1][r2][c2] == -1) printf("-1\n");
    else printf("%d\n", d[0][r1][c1]+d[1][r2][c2]);
}