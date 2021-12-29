#define ms(x, y) memset(x, y, sizeof(x))
class Solution {
public:
    int dp[1005]; //1 = winning state, 0 = losing state
    
    bool fun(int n) {
        if (n == 1) return 0;
        if (dp[n] != -1) return dp[n];
        bool ret = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                ret = max(ret, !fun(n - i));
            }
        }
        return dp[n] = ret;
    }
    
    bool divisorGame(int N) {
        ms(dp, -1);
        return fun(N);
    }
};