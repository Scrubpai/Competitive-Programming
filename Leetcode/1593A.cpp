class Solution {
public:
    int n; string str;
    int cnt(int mask) {
        int ret = 0;
        for (int i = n; i >= 0; i--) {
            if (mask & (1 << i)) ret++;
        }
        return ret;
    }
    bool check(int mask) {
        int pre = 0, num = 0; unordered_set<string> st;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                num++;
                st.insert(str.substr(pre, i - pre + 1));
                pre = i + 1;
            }
        }
        st.insert(str.substr(pre, n - pre + 1)); num++;
        return st.size() == num;
    }
    int maxUniqueSplit(string s) {
        n = s.size(); n--; str = s;
        int ans = 1;
        for (int i = 1; i < (1 << n); i++) {
            if (cnt(i) < ans) continue;
            if (check(i)) {
                ans = max(ans, cnt(i) + 1);
            }
        }
        return ans;
    }
};