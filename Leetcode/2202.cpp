class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int ans = 0, n = (int)nums.size();
        if (!k) return nums[0];
        if (n == 1) {
            if (k % 2 == 1) return -1;
            else return nums[0];
        }
        
        for (int i=0; i<n; i++) {
            if (i+1 == k) continue;
            if (i == k || k > i+1) ans = max(ans, nums[i]);
        }
        return ans;
    }
};