class Solution {
public:
    vector<int> pos;
    string reorderSpaces(string text) {
        int n = text.size(), cnt = 0, words = 0;
        for (int i = 0; i < n; i++) {
            if (text[i] == ' ') { 
                if (i > 0 && text[i-1] != ' ') words++;
                cnt++;
            }
        }
        if (text[n-1] != ' ') words++; 
        int num = 0, rem = cnt;
        if (words - 1 > 0) { num = cnt / (words - 1); rem = cnt % (words - 1); }
        string ans = ""; stringstream ss(text); string word;
        while (ss >> word) {
            words--; ans += word;
            cout << words << " " << word << endl;
            if (words) {
                for (int i = 0; i < num; i++) ans += " ";
            }
        }
        for (int i = 0; i < rem; i++) ans += " ";
        return ans;
    }
};