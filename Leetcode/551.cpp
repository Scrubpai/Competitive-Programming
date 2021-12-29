class Solution {
public:
    int cntA = 0;
    bool checkRecord(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                cntA++;
                if (cntA > 1) return 0;
            } else if (s[i] == 'L') {
                if (i > 1) {
                    if (s[i-1] == 'L' && s[i-2] == 'L') return 0;
                }
            }
        }
        return 1;
    }
};