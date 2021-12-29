const int MM = 1e5 + 5;
class Solution {
public:
    int dsu[MM], a[MM], sz[MM];
    int Find(int u) {
        if (dsu[u] == u) return u;
        else return dsu[u] = Find(dsu[u]);
    }
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size(), cnt = 0, mx = -1;
        for (int i = 1; i <= n; i++) dsu[i] = i;
        for (int i = 0; i < arr.size(); i++) {
            a[arr[i]] = 1; sz[arr[i]]++;
            if (a[arr[i]-1]) {
                int fu = Find(arr[i]-1);
                 dsu[fu] = arr[i];
                 if (sz[fu] == m) cnt--;
                 sz[arr[i]] += sz[fu];
            }
            if (a[arr[i]+1]) {
                int fu = Find(arr[i]+1);
                dsu[fu] = arr[i];
                 if (sz[fu] == m) cnt--;
                 sz[arr[i]] += sz[fu];
            }
            if (sz[arr[i]] == m) cnt++;
            if (cnt) mx = max(mx, i+1);
        }
        return mx;
    }
};