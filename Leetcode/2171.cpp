class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = (int)beans.size();
        sort(beans.begin(), beans.end());
        long long ans = 1e18, cur = 0, tot = 0;
        for (int i=0; i<n; i++) tot += beans[i];
        for (int i=0; i<n; i++) {
            ans = min(ans, tot - 1ll * beans[i] * (n-i));
            cur += beans[i];
        }
        return ans;
    }
};