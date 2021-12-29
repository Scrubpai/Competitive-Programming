class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size(); int ans = 0;
        sort(piles.rbegin(), piles.rend()); int cnt = 0;
        for (int i = 1; i < n; i+=2) {
            cnt++; ans += piles[i];
            if (cnt == n / 3) return ans;
        }
        return ans;
    }
};