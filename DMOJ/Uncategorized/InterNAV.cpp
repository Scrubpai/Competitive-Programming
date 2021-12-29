#include <bits/stdc++.h>
using namespace std;
int r, c, r0, c0, d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; char g[1005][1005]; vector<int> ans;
void dfs(int x, int y) {
    if (g[x][y] >= '1' && g[x][y] <= '9') ans.push_back(g[x][y]-'0');
    g[x][y] = '#';
    for (int k=0; k<4; k++) {
        int nr = x+d[k][0], nc = y+d[k][1];
        if (nr>=1 && nr<=r && nc>=1 && nc<=c && g[nr][nc] != '#') dfs(nr, nc);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> c >> r;
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            cin >> g[i][j];
            if (g[i][j] == '1') r0 = i, c0 = j;
        }
    }
    dfs(r0, c0); sort(ans.begin(), ans.end());
    for (int x : ans) printf("%d ", x);
    return 0;
}