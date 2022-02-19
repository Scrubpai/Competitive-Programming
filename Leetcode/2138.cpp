class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int cur = 0; string t = "";
        for (int i=0; i<(int)s.size(); i++) {
            cur++; t += s[i];
            if (cur == k) cur = 0, ans.push_back(t), t="";
        }
        if (cur) {
            for (int i=cur+1; i<=k; i++) t+=fill;
            ans.push_back(t);
        }
        return ans;
    }
};