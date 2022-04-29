class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = (int)nums.size(), ans = 0;
        for (int i=1; i<n-1; i++) {
            int tmp = -1;
            for (int j=i-1; j>=0; j--) {
                if (nums[j] < nums[i]) tmp = 0;
                else if (nums[j] > nums[i]) tmp = 1;
                break;
            }
            if (tmp == -1) continue;
            for (int j=i+1; j<n; j++) {
                if (nums[j] == nums[i]) continue;
                if (i == 3) cout << tmp << '\n';
                if ((tmp == 0 && nums[j] < nums[i]) || (tmp == 1 && nums[j] > nums[i])) ans++;
                break;
            }
        }
        return ans;
    }
};