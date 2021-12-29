class Solution {
public:
    int minInsertions(string s) {
        int n = s.size(), ans = 0; double lft = 0; s += ' ';
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') lft++;
            else lft -= 0.5;
            
            if (lft == -0.5) {
                if (s[i+1] == ')') continue;
                else {
                    lft = 0; ans += 2;
                }
            } else if (lft == -1) {
                lft++; ans++;
            } else if (ceil(lft) - lft == 0.5) {
                if (s[i+1] == ')') continue;
                else { lft -= 0.5; ans++; }
            }
        }
        return ans + 2 * lft;
    }
};