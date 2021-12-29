const int MM = 1 << 12;
#define INF 0x3f3f3f3f
class Solution {
public:
    int dp[13][MM+5];
    int connectTwoGroups(vector<vector<int>>& cost) {
        int sz1 = cost.size(), sz2 = cost[0].size();
        memset(dp, INF, sizeof(dp)); dp[0][0] = 0;
        for (int i = 1; i <= sz1; i++) {
            for (int mask = 0; mask < (1 << sz2); mask++) {
                for (int j = 0; j < sz2; j++) {
                    int nmask = mask | (1 << j);
                    dp[i][nmask] = min(dp[i][nmask], dp[i-1][mask] + cost[i-1][j]);
                }
            }
        }
        int ans = INF;
        for (int mask = 0; mask < (1 << sz2); mask++) {
            int sum = 0;
            for (int j = 0; j < sz2; j++) {
                if (!(mask & (1 << j))) {
                    int mn = INF;
                    for(int i = 0; i < sz1; i++) {
                        mn = min(mn, cost[i][j]);
                    }
                    sum += mn;
                }
            }
            ans = min(ans, dp[sz1][mask] + sum);
        }
        return ans;
    }
};