class Solution {
public:
    vector<string> cellsInRange(string s) {
        char a[2], b[2]; vector<string> ans;
        a[0] = s[0]; a[1] = s[1]; b[0] = s[3]; b[1] = s[4];
        for (char c=a[0]; c<=b[0]; c++) {
            for (char x=a[1]; x<=b[1]; x++) {
                string t; t.push_back(c); t.push_back(x);
                ans.push_back(t);
            }
        }
        return ans;
    }
};