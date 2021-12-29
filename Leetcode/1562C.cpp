const int MM = 1e5 + 5;
class Solution {
public:
    int len[MM], cnt[MM], res = -1;
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int v = arr[i], l = v - len[v-1], r = v + len[v+1];
            cnt[len[v-1]]--; cnt[len[v+1]]--; cnt[r-l+1]++;
            len[l] = len[r] = len[v] = r - l + 1;
            if (cnt[m]) res = i + 1;
        }
        return res;
    }
};