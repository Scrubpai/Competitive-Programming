class Solution {
public:
    vector<int> ans;
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())  {
            ans.push_back(-1); ans.push_back(-1);
            return ans;
        }
        int idx1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int idx2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (idx1 == nums.size() || nums[idx1] != target) {
            ans.push_back(-1); ans.push_back(-1);
        } else {
            ans.push_back(idx1); ans.push_back(idx2-1);
        }
        return ans;
    }
};