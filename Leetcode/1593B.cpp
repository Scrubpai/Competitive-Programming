class Solution {
public:
    unordered_set<string> st;
    int dfs(string &s, int pos) {
        if (pos == s.size()) return 0;
        int res = -1;
        for (int sz = 1; sz + pos <= s.size(); sz++) {
            auto it = st.insert(s.substr(pos, sz));
            if (it.second) {
                int nxt = dfs(s, pos + sz);
                if (nxt != -1) res = max(res, 1 + nxt);
                st.erase(it.first);
            }
        }
        return res;
    }
    int maxUniqueSplit(string s) {
        return dfs(s, 0);
    }
};