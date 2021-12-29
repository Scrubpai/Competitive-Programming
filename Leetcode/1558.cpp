class Solution {
public:
    int cnt1 = 0, cnt2 = 0;
    int getVal(int x) {
        if (x < 1) return x;
        if (x % 2 == 1) {
            cnt1++;
            return getVal(x-1);
        }
        else return 1 + getVal(x / 2);
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            cnt2 = max(cnt2, getVal(nums[i]));
        }
        return cnt1 + cnt2;
    }
};