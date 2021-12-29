const int MM = 1e5 + 5;
class Solution {
public:
    int a[MM], n, ans;
    int getMaxLen(vector<int>& nums) {
        n = nums.size();
        for (int i = 0; i < n; i++) a[i+1] = nums[i];
        int last = 0, idx1 = MM, idx2 = 0, neg = 0;
        for (int i = 1; i <= n + 1; i++) {
            if (a[i] < 0) neg++, idx1 = min(idx1, i), idx2 = max(idx2, i); 
            if (a[i] == 0) {
                if (neg % 2 == 1) {
                    ans = max(ans, i - idx1 - 1);
                    ans = max(ans, idx2 - last - 1);
                    idx1 = MM; idx2 = 0; neg = 0;
                } else {
                    ans = max(ans, i - last - 1);
                    idx1 = MM; idx2 = 0; neg = 0;
                }
                last = i;
           //     if (ans == 4) cout << i << endl;
            }
        }
        return ans;
    }
};