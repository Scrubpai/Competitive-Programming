typedef long long ll;
const int MM = 1e5;
class Solution {
public:
    ll dp[MM+5];
    long long mostPoints(vector<vector<int>>& questions) {
        int n = (int)questions.size();
        for (int i=n; i>=1; i--) {
            dp[i] = questions[i-1][0] + dp[min(MM+1, i+questions[i-1][1]+1)];
            dp[i] = max(dp[i], dp[i+1]);
        }
        return dp[1];
    }
};