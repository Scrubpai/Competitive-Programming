class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int j = 0, n = nums.size(), ans = 0;
        while (j < n) {
            int i = j, cnt = 0, first = -1, last = -1;
            while (j < n && nums[j] != 0) {
                if (nums[j] < 0) {
                    cnt++;
                    if (first == -1) first = j;
                    last = j;
                }                
                j++;
            }
            if (cnt % 2) ans = max(ans, max(j - first - 1, last - i));
            else ans = max(ans, j - i);
            while (j < n && nums[j] == 0) j++;
        }
        return ans;
    }
};