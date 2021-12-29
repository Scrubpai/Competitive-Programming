typedef pair<int, int> pii;
#define ms(x, y) memset(x, y, sizeof(x))
class Solution {
public:
    int a[35][35], r, c; bool vis[35][35];
    void dfs(int i, int j) {
        vis[i][j] = 1;
        if (a[i+1][j] && !vis[i+1][j]) dfs(i+1, j);
        if (a[i][j+1] && !vis[i][j+1]) dfs(i, j+1);
        if (a[i][j-1] && !vis[i][j-1]) dfs(i, j-1);
        if (a[i-1][j] && !vis[i-1][j]) dfs(i-1, j);
    }
    int minDays(vector<vector<int>>& grid) {
        r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                a[i+1][j+1] = grid[i][j];
            }
        }
        int cnt = 0;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (a[i][j] && !vis[i][j]) {
                    dfs(i, j); cnt++;
                }
            }
        }
        if (cnt != 1) return 0;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (a[i][j]) {
                    a[i][j] = 0; cnt = 0; ms(vis, 0);
                    for (int x = 1; x <= r; x++) {
                        for (int y = 1; y <= c; y++) {
                            if (a[x][y] && !vis[x][y]) {
                                dfs(x, y); cnt++;
                            }
                        }
                    }
                    a[i][j] = 1;
                    if (cnt != 1) {
                        return 1;
                    }
                }
            }
        }
        return 2;
    }
};