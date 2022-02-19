class Solution {
public:
    int n, ans, vis[16];
    int maximumGood(vector<vector<int>>& statements) {
        n = (int)statements.size();
        for (int mask=0; mask<(1<<n); mask++) {
            for (int i=0; i<n; i++) {
                if (mask&(1<<i)) vis[i] = 1;
                else vis[i] = 0;
            }
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (statements[i][j] == 2) continue;
                    if (statements[i][j] == 1) {
                        if (vis[i] == 1 && vis[j] == 0) goto next;
                    } else {
                        if (vis[i] == 1 && vis[j] == 1) goto next;
                    }
                }
            }
            ans = max(ans, __builtin_popcount(mask));
            next: ;
        }
        return ans;
    }
};