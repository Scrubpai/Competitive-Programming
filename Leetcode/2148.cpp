class Solution {
public:
    int countElements(vector<int>& nums) {
        int l=-1, r=-1;
        sort(nums.begin(), nums.end());
        if ((int)nums.size() <= 2) return 0;
        for (int i=1; i<(int)nums.size(); i++) {
            if (nums[i] != nums[i-1]) { l = i; break; }
        }
        for (int i=(int)nums.size()-2; i>=0; i--) {
            if (nums[i] != nums[i+1]) { r = i; break; }
        }
        if (r < l || l==-1 || r==-1) return 0;
        else return r-l+1;
    }
};