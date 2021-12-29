class Solution {
public:
    int R[105], C[105];
    int numSpecial(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j]) {
                    R[i]++; C[j]++;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] && R[i] == 1 && C[j] == 1) cnt++;
            }
        }
        return cnt;
    }
};