const int MOD = 1e9 + 7;
typedef long long ll;
class Solution {
public:
    ll a[20][20], dp[20][20][2];
    
    int maxProductPath(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size(); bool flag = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                a[i+1][j+1] = grid[i][j];
                if (a[i+1][j+1] == 0) flag = 1;
            }
        }
        memset(dp, -1, sizeof(dp));
        if (a[1][1] >= 0) dp[1][1][1] = a[1][1];
        else dp[1][1][0] = -a[1][1];
        
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (dp[i-1][j][0] != -1) {
                    bool pos = (-dp[i-1][j][0] * a[i][j] >= 0);
                    dp[i][j][pos] = max(dp[i][j][pos], abs(dp[i-1][j][0] * a[i][j]));
                }
                if (dp[i][j-1][0] != -1) {
                    bool pos = (-dp[i][j-1][0] * a[i][j] >= 0);
                    dp[i][j][pos] = max(dp[i][j][pos], abs(dp[i][j-1][0] * a[i][j]));
                }
                if (dp[i-1][j][1] != -1) {
                    bool pos = (dp[i-1][j][1] * a[i][j] >= 0);
                    dp[i][j][pos] = max(dp[i][j][pos], abs(dp[i-1][j][1] * a[i][j]));
                }
                if (dp[i][j-1][1] != -1) {
                    bool pos = (dp[i][j-1][1] * a[i][j] >= 0);
                    dp[i][j][pos] = max(dp[i][j][pos], abs(dp[i][j-1][1] * a[i][j]));
                }
            }
        }
        if (dp[r][c][1] == -1) {
            if (flag) return 0;
            return -1;
        }
        else return dp[r][c][1] % MOD;
    }
};