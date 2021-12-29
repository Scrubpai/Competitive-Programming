const int MM = 1e4 + 5;
class Solution {
public:
    vector<int> adj[MM], res; int ans[MM]; bool vis[5];
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        for (int i = 0; i < paths.size(); i++) {
            int u = paths[i][0], v = paths[i][1];
            adj[u].push_back(v); adj[v].push_back(u);
        }
        for (int i = 1; i <= N; i++) {
            memset(vis, 0, sizeof(vis));
            for (int v : adj[i]) {
                vis[ans[v]] = 1;
            }
            for (int j = 1; j <= 4; j++) {
                if (!vis[j]) { ans[i] = j; break; }
            }
            res.push_back(ans[i]);
        }
        return res;
    }
};