const int MOD = 1e9 + 7;
class Solution {
public:
    int numWays(string s) {
        int n = s.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') cnt++;
        }
        if (cnt % 3 != 0) return 0;
        if (cnt == 0) {
            int ans = (((1LL * (n - 1) * (n - 2)) % MOD) / 2) % MOD;
            return ans;
        }
        int need = cnt / 3, way1 = 0, way2 = 0, a = 0, b = 0; bool flag = 0;
        for (int i = 0; i < n - 2; i++) {
            if (s[i] == '1') {
                a++;
                if (a == need) flag = 1;
                else flag = 0;
            }
            if (flag) way1++;
        }
        flag = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                b++;
                if (b == 2 * need) flag = 1;
                else flag = 0;
            }
            if (flag) way2++;
        }
        int ans = ((1LL * way1 * way2) % MOD) % MOD;
        return ans;
    }
};