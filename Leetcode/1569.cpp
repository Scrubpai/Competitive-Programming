typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    ll pascalT[1005][1005];
    
    ll dfs(vector<int> nums) {
        int n = nums.size();
        if (n <= 2) return 1;
        vector<int> left, right;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else if (nums[i] > nums[0]) right.push_back(nums[i]);
        }
        ll x = dfs(left) % MOD, y = dfs(right) % MOD;
        return (1LL * ((pascalT[n-1][left.size()] * x) % MOD) * y) % MOD;
    }
    
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) pascalT[i][j] = 1;
                else pascalT[i][j] = (pascalT[i-1][j] + pascalT[i-1][j-1]) % MOD;
            }
        }
        return (dfs(nums)) % MOD - 1;
    }
};