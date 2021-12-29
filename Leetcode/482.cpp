class Solution {
public:
    string newstr;
    string licenseKeyFormatting(string S, int K) {
        int cnt = 0, idx = -1;
        for (int i = 0; i < S.size(); i++) { if (S[i] != '-') { idx = i; break; }}
        for (int i = S.size() - 1; i >= 0; i--) {
            if (S[i] == '-') continue;
            cnt++; newstr += putchar(toupper(S[i]));
            if (cnt == K && i != idx) newstr += "-", cnt = 0; 
        }
        reverse(newstr.begin(), newstr.end());
        return newstr;
        
    }
};