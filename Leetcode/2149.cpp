class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans, pos, neg; int zero = 0;
        for (int i=0; i<(int)nums.size(); i++) {
            if (nums[i]>0) pos.push_back(nums[i]);
            else if (nums[i]<0) neg.push_back(nums[i]);
            else zero++;
        }
        for (int i=0; i<(int)pos.size(); i++) {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        for (int i=0; i<zero; i++) ans.push_back(0);
        return ans;
    }
};