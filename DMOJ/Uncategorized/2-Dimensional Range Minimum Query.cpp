#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 1005, LOG = 10;
int st[LOG+5][MM][LOG+5][MM];
void init(vector<vector<int>> arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            st[0][i][0][j] = arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= LOG; j++) {
            for (int k = 0; k + (1<<(j-1)) < n; k++) {
                st[0][i][j][k] = min(st[0][i][j-1][k], st[0][i][j-1][k+(1<<(j-1))]);
            }
        }
    }
    for (int i = 1; i <= LOG; i++) {
        for (int j = 0; j + (1<<(i-1)) < n; j++) {
            for (int k = 0; k <= LOG; k++) {
                for (int l = 0; l < n; l++) {
                    st[i][j][k][l] = min(st[i-1][j][k][l], st[i-1][j+(1<<(i-1))][k][l]);
                }
            }
        }
    }
}
int query(int x1, int x2, int y1, int y2) {
    int kx = log2(x2 - x1 + 1), ky = log2(y2 - y1 + 1);
    return min({st[kx][x1][ky][y1], st[kx][x1][ky][y2-(1<<ky)+1], st[kx][x2-(1<<kx)+1][ky][y1], st[kx][x2-(1<<kx)+1][ky][y2-(1<<ky)+1]});
}