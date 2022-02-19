const int MM = (1<<18);
class Solution {
public:
    int dp[2][MM];
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = (int)nums.size(), ans = 0;
        memset(dp, -1, sizeof(dp)); dp[0][0] = 0;
        for (int i=0; i<n; i++) {
            for (int mask=0; mask<(1<<(2*numSlots)); mask++) {
                int cnt = __builtin_popcount(mask);
                if (cnt != i || dp[0][mask] == -1) continue;
                for (int j=0; j<2*numSlots; j++) {
                    if (!(mask&(1<<j))) {
                        int slot = j/2 + 1;
                        dp[1][mask|(1<<j)] = max(dp[1][mask|(1<<j)], dp[0][mask] + (nums[i] & slot));
                    }
                }
            }
            for (int mask=0; mask<(1<<(2*numSlots)); mask++) dp[0][mask] = dp[1][mask], dp[1][mask] = -1;
        }
        for (int mask=0; mask<(1<<(2*numSlots)); mask++) {
            int cnt = __builtin_popcount(mask);
            if (cnt == n) ans = max(ans, dp[0][mask]);
        }
        return ans;
    }
};