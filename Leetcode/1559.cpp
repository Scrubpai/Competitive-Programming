class Solution {
public:
    int dis[505][505], dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }, m, n; char a[505][505];
    
    bool dfs(int r, int c, char ch) {
        for (int k = 0; k < 4; k++) {
            int nr = r + dir[k][0], nc = c + dir[k][1];
            if (nr >= 1 && nr <= m && nc >= 1 && nc <= n && a[nr][nc] == ch) {
                if (dis[nr][nc] && dis[r][c] - dis[nr][nc] >= 3) {
                    return 1;
                }
                else if (!dis[nr][nc]) {
                    dis[nr][nc] = dis[r][c] + 1;
                    if (dfs(nr, nc, ch)) return 1;
                }
            }
        }
        return 0;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(); n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[i+1][j+1] = grid[i][j];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (!dis[i][j]){
                    dis[i][j] = 1;
                    if (dfs(i, j, a[i][j])) return 1;
                }
            }
        }
        return 0;
    }
};