const int MM = 1e5 + 5;
class Solution {
public:
    int in[MM]; vector<int> ans;
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            in[v]++;
        }
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};