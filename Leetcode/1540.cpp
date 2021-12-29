class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n = s.size(), m = t.size(), shift[30];
        if (n != m) return 0;
        for (int i = 1; i <= 25; i++) shift[i] = 0;
        for (int i = 0; i < n; i++) {
            int a = s[i]-'a', b = t[i]-'a';
            shift[(25-a+b+1)%26]++;
        }
        for (int i = 1; i <= 25; i++) {
            if (shift[i] == 0) continue;
            if (i > k) return 0;
            int x = (int)(k / 26);
            if ((x + 1 == shift[i] && k - 26 * x < i) || x + 1 < shift[i]) return 0;
        }
        return 1;
    }
};