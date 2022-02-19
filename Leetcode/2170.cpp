const int MM = 1e5+5;
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1) return 0;
        vector<int> even(MM, 0), odd(MM, 0);
        int mx1 = 0, mx2 = 0;
        for (int i=0; i<n; i++) {
            if (i&1) odd[nums[i]]++;
            else even[nums[i]]++;
        }
        for (int i=1; i<=100000; i++) {
            if (even[i] > even[mx1]) mx2 = mx1, mx1 = i;
            else if (even[i] > even[mx2]) mx2 = i;
        }
        int o = (n+1)/2, e = n/2, ans = 1e9;
        for (int i=1; i<=100000; i++) {
            if (i == mx1) {
                ans = min(ans, o-odd[i] + e-even[mx2]);
            } else {
                ans = min(ans, o-odd[i] + e-even[mx1]);
            }
        }
        return ans;
    }
};