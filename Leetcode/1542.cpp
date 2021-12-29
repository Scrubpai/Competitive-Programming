class Solution {
public:
    int idx[1 << 11];
    int longestAwesome(string s) {
        int n = s.size(); int mask = 0; memset(idx, -1, sizeof(idx)); int ans = 0;
        idx[0] = 0;
        for (int i = 1; i <= n; i++) {
            mask ^= (1 << (s[i-1]-'0'));
            if (idx[mask] != -1) ans = max(ans, i - idx[mask]);
            
            for (int j = 0; j < 10; j++) {
                int nmask = mask ^ (1 << j);
                if (idx[nmask] != -1) {
                    ans = max(ans, i - idx[nmask]);
                }
            }
            if (idx[mask] == -1) idx[mask] = i;
        }
        return ans;
    }
};