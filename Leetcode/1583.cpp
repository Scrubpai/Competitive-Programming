class Solution {
public:
    int a[505][505], p[505];
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < preferences[i].size(); j++) {
                a[i][preferences[i][j]] = j;
            }
        }
        for (int i = 0; i < n/2; i++) {
            int u = pairs[i][0], v = pairs[i][1];
            p[u] = v; p[v] = u;
        }
        for (int i = 0; i < n; i++) {
            int cur_pref = a[i][p[i]];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                //i prefers j over current, and j prefers i over his
                if (a[i][j] < cur_pref && a[j][i] < a[j][p[j]]) { ans++; break; }
            }
        }
        return ans;
    }
};