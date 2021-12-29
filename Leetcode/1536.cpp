class Solution {
public:
    int a[205][205], idx[205];
    int minSwaps(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                a[i + 1][j + 1] = grid[i][j];
            }
        }
        
        int n = grid.size(); memset(idx, -1, sizeof(idx));
        for (int i = 1; i <= n; i++) {
            for(int j = n; j >= 1; j--) {
                if (a[i][j]) { idx[i] = j; break; }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (idx[i] <= i) continue;
            int j = -1;
            for (int k = i + 1; k <= n; k++) {
                if (idx[k] <= i) { j = k; break; }
            }
            if (j == -1) return -1;
            for (int k = j - 1; k >= i; k--) swap(idx[k], idx[k + 1]);
            ans += j - i;
        }
        return ans;
    }
};