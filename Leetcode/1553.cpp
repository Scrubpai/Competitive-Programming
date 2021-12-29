class Solution {
public:
    unordered_map<int, int> dp;
    int dfs(int cur) {
        if (cur <= 1) return cur;
        if (dp[cur] != 0) return dp[cur];
        return dp[cur] = min(cur % 2 + dfs(cur / 2), cur % 3 + dfs(cur / 3)) + 1;
    }
    
    int minDays(int n) {
        return dfs(n);
    }
};