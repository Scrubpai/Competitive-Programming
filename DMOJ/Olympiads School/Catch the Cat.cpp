#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5;
int X, Y, dis[MM+1];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> X >> Y; memset(dis, 0x3f, sizeof(dis));
    queue<int> q; q.push(X); dis[X] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == Y) { printf("%d\n", dis[u]); return 0; }
        if (u && dis[u-1] > dis[u] + 1) { dis[u-1] = dis[u] + 1; q.push(u-1); }
        if (u<MM && dis[u+1] > dis[u] + 1) { dis[u+1] = dis[u] + 1; q.push(u+1); }
        if (2*u<=MM && dis[2*u] > dis[u] + 1) { dis[2*u] = dis[u] + 1; q.push(2*u); }
    }
}