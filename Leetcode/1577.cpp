const int MM = 1e5 + 5;
#define ms(x, y) memset(x, y, sizeof(x))
typedef long long ll;
class Solution {
public:
    int freq[MM];
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            ms(freq, 0);
            ll need = 1LL * nums1[i] * nums1[i];
            for (int j = 0; j < m; j++) {
                if (need % nums2[j] == 0) {
                    ll d = 1LL * need / nums2[j];
                    if (d >= 1 && d <= MM - 5) ans += freq[need / nums2[j]];
                }
                freq[nums2[j]]++;
            }
        }
        for (int i = 0; i < m; i++) {
            ms(freq, 0);
            ll need = 1LL * nums2[i] * nums2[i];
            for (int j = 0; j < n; j++) {
                if (need % nums1[j] == 0) {
                    ll d = 1LL * need / nums1[j];
                    if (d >= 1 && d <= MM - 5) ans += freq[need / nums1[j]];
                }
                freq[nums1[j]]++;
            }
        }
        return ans;
    }
};