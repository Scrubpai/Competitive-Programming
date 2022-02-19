/*
Idea: The minimum time to remove all "1" will invove
    1) Removing some prefix of trains (left)
    2) Removing some suffix of trains (right)
    3) Removing the remaining "1"s using 2 units of time (mid)

Visualization: | left | mid | right |
Define len(x) as the length of the interval
Define count(x, y) as the number of y's in the interval of x

Using an O(n^2) solution, we can brute force the left (l) and right (r) endpoints of mid
    ans = min(ans, len(left) + 2 * count(mid, 1) + len(right))
    ans = min(ans, l + 2*(psa[r] - psa[l-1]) + N-r+1))

Optimize to O(n):
    Let's examine len(left) + 2 * count(mid, 1) + len(right)
    We can add and subtract len(mid) to this 

    (len(left) + len(mid) + len(right)) + (2 * count(mid, 1) - len(mid))
    = N + (2 * count(mid, 1) - len(mid))

    len(mid) = count(mid, 0) + count(mid, 1) because there are only 0's and 1's

    Then it results to = N + count(mid, 1) - count(mid, 0) as the time required to remove all "1"s
    We want to find the minimal count(mid, 1) - count(mid, 0)

    This problem is just minimum sum subarray! -- O(n) DP
    Let dp[i] = minimum subarray sum for the first i numbers and MUST include the i-th number

    dp[i] = min(nums[i], dp[i-1] + nums[i])
*/

class Solution {
public:
    int minimumTime(string s) {
        int n = (int)s.size(); s = " " + s; vector<int> nums(n+1), dp(n+1);
        for (int i=1; i<=n; i++) {
            if (s[i] == '0') nums[i] = -1;
            else nums[i] = 1;
        }
        int ans = 0;
        for (int i=1; i<=n; i++) {
            dp[i] = min(nums[i], dp[i-1] + nums[i]);
            ans = min(ans, dp[i]);
        }
        return ans+n;
    }
};