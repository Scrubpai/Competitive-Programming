#include <bits/stdc++.h>
using namespace std;
struct px {
    int i, j, d, c;
    bool operator < (const px &a) const {
        if (d != a.d) return d > a.d;
        else return c > a.c;
    }
};
int N, M, K, c[1501][1501], dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M >> K; priority_queue<px> pq;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> c[i][j];
        }
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (!c[i][j]) continue;
            if (i>1 && !c[i-1][j]) pq.push({i-1, j, 1, c[i][j]});
            if (j>1 && !c[i][j-1]) pq.push({i, j-1, 1, c[i][j]});
            if (i<N && !c[i+1][j]) pq.push({i+1, j, 1, c[i][j]});
            if (j<M && !c[i][j+1]) pq.push({i, j+1, 1, c[i][j]});
        }
    }
    while (!pq.empty()) {
        px u = pq.top(); pq.pop();
        if (c[u.i][u.j] || u.d>K) continue;
        c[u.i][u.j] = u.c;
        for (int k=0; k<4; k++) {
            int nr = u.i + dir[k][0], nc = u.j + dir[k][1];
            if (nr>=1 && nr<=N && nc>=1 && nc<=M && !c[nr][nc]) pq.push({nr, nc, u.d+1, c[u.i][u.j]});
        }
    }
    for (int i=1; i<=N; i++) {
        cout << c[i][1];
        for (int j=2; j<=M; j++) {
            cout << " " << c[i][j];
        }
        cout << '\n';
    }
}