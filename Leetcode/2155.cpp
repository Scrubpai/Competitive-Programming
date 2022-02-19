class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> ans, pre(n+1), suf(n+2);
        for (int i=1; i<=n; i++) {
            if (nums[i-1] == 0) pre[i] = 1;
            pre[i] += pre[i-1];
        }
        for (int i=n; i>=1; i--) {
            if (nums[i-1] == 1) suf[i] = 1;
            suf[i] += suf[i+1];
        }
        int mx = 0;
        for (int i=0; i<=n; i++) {
            if (pre[i] + suf[i+1] > mx) {
                mx = pre[i] + suf[i+1];
                ans.clear(); ans.push_back(i);
            } else if (pre[i] + suf[i+1] == mx) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};