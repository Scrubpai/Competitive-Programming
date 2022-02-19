class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd, even;
        for (int i=0; i<(int)nums.size(); i++) {
            if (i&1) odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        sort(odd.begin(), odd.end(), greater<>()); sort(even.begin(), even.end());
        vector<int> ans;
        for (int i=0, j=0, k=0; i<(int)nums.size(); i++) {
            if (i&1) ans.push_back(odd[j++]);
            else ans.push_back(even[k++]);
        }
        return ans;
    }
};