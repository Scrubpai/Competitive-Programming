class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size(), missing[2005], cnt = 0, cur = 0;
        for (int i = 1; i <= 2000; i++) {
            if (cur < arr.size() && arr[cur] == i) cur++;
            else missing[++cnt] = i;
        }
        return missing[k];
    }
};