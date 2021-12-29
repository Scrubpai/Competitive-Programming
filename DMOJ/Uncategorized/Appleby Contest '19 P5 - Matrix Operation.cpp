#include <bits/stdc++.h>
using namespace std;
int N, a[1505][1505], d[1505][1505], dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}}, ans;
int dfs(int i, int j) {
    if (d[i][j] != -1) return d[i][j];
    d[i][j] = 0;
    for (int k=0; k<4; k++) {
        int r = i+dir[k][0], c = j+dir[k][1];
        if (r && c && r<=N && c<=N && a[r][c] > a[i][j]) d[i][j] = max(d[i][j], dfs(r, c) + 1);
    }
    return d[i][j];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> a[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (d[i][j] == -1) dfs(i, j);
            ans = max(ans, d[i][j]);
        }
    }
    printf("%d\n", ans);
}