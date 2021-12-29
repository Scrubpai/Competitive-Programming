#include <bits/stdc++.h>
using namespace std;
const int MM = (1<<13)+2;
int N, Q, h[MM], bit[MM][MM];
void update(int r, int c, int val) {
    for (int i=r; i<=N; i+=i&-i) {
        for (int j=c; j<=N; j+=j&-j) {
            bit[i][j] += val;
        }
    }
}
int query(int r, int c) {
    int ans = 0;
    for (int i=r; i; i-=i&-i) {
        for (int j=c; j; j-=j&-j) {
            ans += bit[i][j];
        }
    }
    return ans;
}
int solve(int r0, int c0, int r1, int c1) {
    return query(r1, c1) - query(r1, c0) - query(r0, c1) + query(r0, c0);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> h[i];
        update(i+1, h[i]+1, 1);
    }
    cin >> Q;
    for (int q=1, op, i, j, a, b, ht; q<=Q; q++) {
        cin >> op;
        if (op == 1) {
            cin >> i >> j >> a >> b;
            printf("%d\n", solve(i, a, j+1, b+1));
        } else {
            cin >> i >> ht;
            update(i+1, h[i]+1, -1); h[i] = ht; update(i+1, ht+1, 1);
        }
    }
    return 0;
}