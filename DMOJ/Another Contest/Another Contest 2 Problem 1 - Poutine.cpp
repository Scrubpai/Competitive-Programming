#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, Q; ll dis[101][101][101];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    memset(dis, 0x3f, sizeof(dis));
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> dis[1][i][j];
            if (i!=j && !dis[1][i][j]) dis[1][i][j] = 0x3f3f3f3f3f3f3f3f;
        }
    }
    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                dis[1][i][j] = min(dis[1][i][j], dis[1][i][k] + dis[1][k][j]);
            }
        }
    }
    for (int d=2; d<N; d++) {
        for (int k=1; k<=N; k++) {
            for (int i=1; i<=N; i++) {
                for (int j=1; j<=N; j++) {
                    dis[d][i][j] = min(dis[d][i][j], max(dis[d-1][i][k], dis[1][k][j]));
                    dis[d][i][j] = min(dis[d][i][j], max(dis[1][i][k], dis[d-1][k][j]));
                    dis[d][i][j] = min(dis[d][i][j], dis[d-1][i][j]);
                }
            }
        }
    }
    cin >> Q;
    for (int i=1, s, t, d; i<=Q; i++) {
        cin >> s >> t >> d;
        cout << ((dis[d][s][t]==0x3f3f3f3f3f3f3f3f)?0:dis[d][s][t]) << '\n';
    }
}