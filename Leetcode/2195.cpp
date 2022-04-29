typedef long long ll;
class Solution {
public:
    ll sum(int n) {
        return 1ll*n*(n+1)/2;
    }
    long long minimalKSum(vector<int>& nums, int k) {
        int n = (int)nums.size(), pre = 0;
        ll ans = 0; sort(nums.begin(), nums.end());
        for (int i=0; i<n; i++) {
            if (k && nums[i] != pre) {
                int r = min(pre+k, nums[i]-1);
                ans += sum(r) - sum(pre);
                k -= (r - pre);
                pre = nums[i];
            }
        }
        if (k) {
            ans += sum(pre+k) - sum(pre);
        }
        return ans;
    }
};