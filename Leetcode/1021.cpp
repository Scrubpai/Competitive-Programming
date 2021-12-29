class Solution {
public:
    string removeOuterParentheses(string S) {
        int n = S.size(), j = 0; string ans = "";
        while (j < n) {
            int i = j, cnt = 0;
            for (; j < n; j++) {
                if (S[j] == '(') cnt++;
                else cnt--;
                if (cnt == 0) break;
            }
            int len = j - i - 1; j++;
            ans += S.substr(i+1, len);
        }
        return ans;
    }
};