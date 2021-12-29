const int MM = 1e7 + 5;
struct E {
        int u, v, w;
    };
    bool cmp(E a, E b) {
        return a.w < b.w;
    }
class Solution {
public:
    int dsu[1005]; vector<E> edges;
    int Find(int x) {
        if (dsu[x] == x) return x;
        else return dsu[x] = Find(dsu[x]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        for (int i = 1; i <= n; i++) dsu[i] = i;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                edges.push_back({i+1, j+1, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
            }
        }
        sort(edges.begin(), edges.end(), cmp);
        int ans = 0;
        for (E e : edges) {
            int fu = Find(e.u), fv = Find(e.v);
            if (dsu[fu] != fv) {
                ans += e.w; dsu[fu] = fv;
            }
        }
        return ans;
    }
};