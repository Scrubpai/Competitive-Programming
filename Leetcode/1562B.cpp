typedef pair<int, int> pii;
class Solution {
public:
    queue<pii> q;
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size(); q.push({1, n});
        for (int i = n - 1; i >= 0; i--) {
            int sz = q.size();
            for (int t = 0; t < sz; t++) {
                pii p = q.front(); q.pop();
                int l = p.first, r = p.second;
                
                if (r - l + 1 == m) return i + 1;
                if (r - l + 1 < m) continue;
                
                if (arr[i] >= l && arr[i] <= r) {
                    if (arr[i] - l >= m) q.push({l, arr[i] - 1});
                    if (r - arr[i] >= m) q.push({arr[i] + 1, r});
                } else {
                    q.push(p);
                }
            }
        }
        return -1;
    }
};