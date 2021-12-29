class Solution {
public:
    int psa[(int)1e5 + 5], dp[(int)1e5 + 5]; unordered_map<long long, int> mp;
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            psa[i+1] = psa[i] + nums[i];
        }
        int ans = 0; mp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int need = psa[i] - target;
            if (mp[need] == 0 && need != 0) dp[i] = 0;
            else dp[i] = dp[mp[need]] + 1;
            mp[psa[i]] = i;
            dp[i] = max(dp[i], dp[i-1]);
        }
        return dp[n];
    }
};