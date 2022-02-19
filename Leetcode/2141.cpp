const int MM = 1e5+5;
typedef long long ll;
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end(), greater<int>());
        ll sum = 0; int b = (int)batteries.size();
        for (int i=n; i<b; i++) sum += batteries[i];
        for (int i=n-1; i>0; i--) {
            if (sum-(n-i)*(batteries[i-1]-batteries[i]) >= 0) {
                sum -= (n-i)*(batteries[i-1]-batteries[i]);
                continue;
            }
            ll v = sum/(n-i);
            return batteries[i]+v;
        }
        ll v = sum/n;
        return batteries[0]+v;
    }
};