class Solution {
public:
    string makeGood(string s) {
        int n = s.size(); string ans = s;
        while (1) {
            bool flag = 0;
            for (int i = 0; i < n - 1; i++) {
                if (ans[i] - 'a' == ans[i+1] - 'A' || ans[i]-'A' == ans[i+1] - 'a') {
                    ans.erase(ans.begin() + i); ans.erase(ans.begin() + i); n-=2; flag = 1; break;
                }
            }
            if (!flag) break;
        }
        return ans;
        
    }
};