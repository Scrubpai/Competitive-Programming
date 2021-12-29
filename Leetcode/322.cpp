#define INF 0x3f3f3f3f // for int
const int MM = 1e5 + 5;
class Solution {
public:
    int dp[MM];
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(); 
        memset(dp, INF, sizeof(dp)); dp[0] = 0;
        for (int i = 0; i < n; i++) {
            int cur = coins[i];
            for (int j = cur; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j-cur] + 1);
            }
        }
        if (dp[amount] == INF) return -1;
        else return dp[amount];
    }
};