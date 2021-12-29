const int MM = 1e5 + 5;
#define INF 0x3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
class Solution {
public:
    int psa[MM];
    int minCost(string s, vector<int>& cost) {
        int n = s.size(); s = " " + s;
        for (int i = 0; i < n; i++) psa[i+1] = psa[i] + cost[i];
        int i = 1, j = 1, ans = 0;
        while (i <= n) {
            int mx = cost[j-1];
            while (i <= n && s[i] == s[j]) {
                mx = max(mx, cost[i-1]);
                i++;
            }
            ans += (psa[i-1] - psa[j-1]) - mx;
            j = i;
        }
        return ans;
    }
};