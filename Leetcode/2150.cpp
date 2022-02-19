const int MM = 1e6;
class Solution {
public:
    int freq[MM+1];
    vector<int> findLonely(vector<int>& nums) {
        for (int i=0; i<(int)nums.size(); i++) freq[nums[i]]++;
        vector<int> ans;
        for (int i=0; i<=MM; i++) {
            if (!i) {
                if ( freq[i]==1 && !freq[i+1]) ans.push_back(i);
            } else if (i==MM) {
                if (freq[i]==1 && !freq[i-1]) ans.push_back(i);
            } else if (freq[i]==1 && !freq[i-1] && !freq[i+1]) ans.push_back(i);
        }
        return ans;
    }
};