class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        const int MOD = 1e9 + 7;
        long long n1 = nums1.size(), n2 = nums2.size(), X = 0, Y = 0, prevx = 0, prevy = 0, i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] > nums2[j]) {
                Y = (Y + nums2[j++]);
            } else if (nums1[i] < nums2[j]) {
                X = (X + nums1[i++]);
            } else {
                X = Y = (max(prevx + nums1[i++], prevy + nums2[j++]));
            }
            prevx = X;
            prevy = Y;
        }
        while (i < n1) X = (X + nums1[i++]);
        while (j < n2) Y = (Y + nums2[j++]);
        return max(X, Y) % MOD;
    }
};