class Solution {
public:
    int minOperations(int n) {
        int need = (1 + (2 * (n-1) + 1)) / 2; int ans = 0;
        for (int i = 1; i <= ceil((double)n/2); i++) {
            int cur = 2 * (i - 1) + 1;
            ans += need - cur;
        }
        return ans;
    }
};