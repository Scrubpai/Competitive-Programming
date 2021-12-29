#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5, LOG=17;
int N, M, st[LOG][MM];
int rmq(int l, int r) {
    int k = log2(r-l+1);
    return max(st[k][l], st[k][r-(1<<k)+1]);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> st[0][i];
    for (int i=1; i<LOG; i++) {
        for (int j=1; j+(1<<i)-1<=N; j++) {
            st[i][j] = max(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }
    for (int i=1, L, R; i<=M; i++) {
        cin >> L >> R;
        printf("%d\n", rmq(L, R));
    }
    return 0;
}