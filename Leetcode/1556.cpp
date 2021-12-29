class Solution {
public:
    string thousandSeparator(int n) {
        string str = to_string(n); string ans = ""; int cnt = 0;
        for (int i = str.size() - 1; i >= 0; i--) {
            cnt++; ans += str[i];
            if (cnt == 3 && i != 0) {
                cnt = 0;
                ans += '.';
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};