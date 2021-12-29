#define ms(x, y) memset(x, y, sizeof(x))
class Solution {
public:
    int psa[505], dp[505][505], n;
    
    int fun(int l, int r) {
        if (r - l + 1 == 1) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        for (int k = l; k < r; k++) {
            if (psa[k] - psa[l-1] > psa[r] - psa[k]) {
                dp[l][r] = max(dp[l][r], psa[r] - psa[k] + fun(k+1, r));
            } else if (psa[k] - psa[l-1] < psa[r] - psa[k]) {
                dp[l][r] = max(dp[l][r], psa[k] - psa[l-1] + fun(l, k));
            } else {
                dp[l][r] = max(dp[l][r], max(psa[k] - psa[l-1] + fun(l, k), psa[r] - psa[k] + fun(k+1, r)));
            }
        }
        return dp[l][r];
    }
    
    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size(); ms(dp, -1);
        for (int i = 0; i < n; i++) {
            psa[i+1] = psa[i] + stoneValue[i];
        }
        return fun(1, n);
    }
};