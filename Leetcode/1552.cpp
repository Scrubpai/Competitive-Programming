const int MM = 1e5 + 5;
class Solution {
public:
    int ans, n;
    
    bool check(int d, vector<int> pos, int M) {
        int cnt = 1, prev = pos[0];
        for (int i = 1; i < n; i++) {
            if (pos[i] - prev >= d) {
             //   cout << pos[i] << " " << prev << " " << d << endl;
                cnt++; prev = pos[i];
            }
        }
        return cnt >= M;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end()); n = position.size();
        int lo = 1, hi = (position[n-1] - position[0]) / (m-1);
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(mid, position, m)) {
                ans = max(ans, mid); lo = mid + 1;
            } else hi = mid - 1;
        }
        return ans;
    }
};