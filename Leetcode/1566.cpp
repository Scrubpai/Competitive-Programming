class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int cnt = 1;
            if (i + m * k > n) break;
            for (int j = i + m; j < n; j += m) {
                bool flag = 1;
                if (j + m - 1 >= n) { return 0;
                }
                for (int x = j; x <= j + m - 1; x++) {
                    if (arr[x] != arr[x-m]) { flag = 0; break; }
                }
                if (flag) {
                    cnt++;
                    if (cnt == k) return 1;
                }
                else break;
            }
        }
        return 0;
    }
};