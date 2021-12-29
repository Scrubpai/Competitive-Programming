const int MM = 1e5 + 5;
struct E {
        int u, v, type;
    };
    bool cmp(E a, E b) {
        return a.type > b.type;
    }
class Solution {
public:
    vector<E> a; int dsu1[MM], dsu2[MM], cnt1, cnt2, used;
    int Find(int x, int dsu[]) {
        if (dsu[x] == x) return x;
        else return dsu[x] = Find(dsu[x], dsu);
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            a.push_back({edges[i][1], edges[i][2], edges[i][0]});
        }
        for (int i = 1; i <= n; i++) dsu1[i] = i, dsu2[i] = i;
        sort(a.begin(), a.end(), cmp);
        for (E e : a) {
            if (e.type == 3) {
                bool flag = 0;
                int fa = Find(e.u, dsu1), fb = Find(e.v, dsu1);
                if (fa != fb) {
                    dsu1[fa] = fb; cnt1++; flag = 1;
                }
                fa = Find(e.u, dsu2); fb = Find(e.v, dsu2);
                if (fa != fb) {
                    dsu2[fa] = fb; cnt2++; flag = 1;
                }
                if (flag) used++;
            } else if (e.type == 1) {
                int fa = Find(e.u, dsu1), fb = Find(e.v, dsu1);
                if (fa != fb) {
                    dsu1[fa] = fb; cnt1++; used++;
                }
            } else {
                int fa = Find(e.u, dsu2), fb = Find(e.v, dsu2);
                if (fa != fb) {
                    dsu2[fa] = fb; cnt2++; used++;
                }
            }
        }
        if (cnt1 != n - 1 || cnt2 != n - 1) return -1;
        return edges.size() - used;
    }
};