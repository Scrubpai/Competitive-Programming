class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<bool> vis(1001);
        for (int i=0; i<(int)nums.size(); i++) {
            vis[nums[i]] = 1;
        }
        while (original <= 1000 && vis[original]) original*=2;
        return original;
    }
};