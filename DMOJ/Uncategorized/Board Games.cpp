#include <bits/stdc++.h>
using namespace std;
const int MM = 1e7;
int N, M, dis[MM+1], dir[3][2] = {{3,0},{1,-1},{1,-3}};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M; memset(dis, -1, sizeof(dis)); dis[N] = 0; queue<int> q; q.push(N);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == M) { printf("%d\n", dis[M]); return 0; }
        for (int k=0; k<3; k++) {
            int nxt = cur*dir[k][0] + dir[k][1];
            if (nxt >= 0 && nxt <= MM && dis[nxt] == -1) dis[nxt] = dis[cur] + 1, q.push(nxt);
        }
        if (cur % 2 == 0 && dis[cur/2] == -1) dis[cur/2] = dis[cur] + 1, q.push(cur/2);
    }
}