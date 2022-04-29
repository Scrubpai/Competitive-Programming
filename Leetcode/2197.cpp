class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = (int)nums.size(); stack<int> st;
        for (int i=0; i<n; i++) {
            int cur = nums[i];
            while (!st.empty() && __gcd(st.top(), cur) > 1) {
                cur = 1ll*st.top()*cur/__gcd(cur, st.top());
                st.pop();
            }
            st.push(cur);
        }
        vector<int> ans;
        while (!st.empty()) { ans.push_back(st.top()); st.pop(); }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};