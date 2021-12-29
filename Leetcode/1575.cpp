const int MOD = 1e9 + 7;
#define ms(x, y) memset(x, y, sizeof(x))
class Solution {
public:
    int loc[205], n, dp[105][205], F;
    int fun(int i, int j) {
        if (j > F) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 0;
        for (int p = 1; p <= n; p++) {
            if (p == i) continue;
            dp[i][j] = (dp[i][j] + fun(p, j + abs(loc[i] - loc[p]))) % MOD;
        }
        return dp[i][j];
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size(); start++; finish++; ms(dp, -1); dp[start][fuel] = 1; F = fuel;
        for (int i = 0; i < n; i++) loc[i+1] = locations[i];
        int ans = 0;
        for (int i = 0; i <= fuel; i++) {
            ans = (ans + fun(finish, i)) % MOD;
            cout << ans << " " << i << endl;
        }
        return ans;
    }
};