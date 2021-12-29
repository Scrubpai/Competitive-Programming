#define INF 0x3f3f3f3f
class Solution {
public:
    int dp[105][105];
    
    int minCost(int n, vector<int>& cuts) {
        int ans = 0; int sz = cuts.size(); sz += 2; cuts.push_back(-1); cuts.push_back(0); cuts.push_back(n); sort(cuts.begin(), cuts.end());
        memset(dp, INF, sizeof(dp));
        //dp[i][j] = minimum cost to achieve all the cuts in [i, j]; 1 <= i, j <= 100
        
        for (int i = 1; i <= sz; i++) dp[i][i] = dp[i][i+1] = 0;
        for (int len = 3; len <= sz; len++) {
            for (int i = 1; i + len - 1 <= sz; i++) {
                int l = i, r = i + len - 1;
                for (int k = l + 1; k < r; k++) {
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + (cuts[r] - cuts[l]));
                }
            }
        }
        return dp[1][sz];
    }
};