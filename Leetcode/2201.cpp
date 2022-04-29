class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> grid(n, vector<int>(n, 0));
        for (int i=0; i<(int)dig.size(); i++) grid[dig[i][0]][dig[i][1]] = 1;
        int ans = 0;
        for (int i=0; i<(int)artifacts.size(); i++) {
            int r1 = artifacts[i][0], c1 = artifacts[i][1], r2 = artifacts[i][2], c2 = artifacts[i][3], flag = 1;
            for (int j=r1; j<=r2; j++) {
                for (int k=c1; k<=c2; k++) {
                    if (grid[j][k] != 1) {
                        flag = 0;
                    }
                }
            }
            if (flag) ans++;
        }
        return ans;
    }
};