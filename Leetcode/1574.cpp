#define INF 0x3f3f3f3f
class Solution {
public:
    int n, lft = 1, rit = 1;
    int findLengthOfShortestSubarray(vector<int>& arr) {
        n = arr.size(); int l = 0, r = n - 1;
        cout << n << endl;
        if (n == 1) return 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i-1]) break;
            lft++; l = i;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i+1]) break;
            rit++; r = i;
        }
        if (l > r) return 0;
        int ans = 0;
        for (int i = 0; i <= l; i++) {
            int tmp = r;
            while (tmp < n && arr[tmp] < arr[i]) tmp++;
            ans = max(ans, i + 1 + (n - tmp));
        }
        cout << ans << " " << lft << " " << rit << endl;
        return min({n - ans, n - lft, n - rit});
    }
};