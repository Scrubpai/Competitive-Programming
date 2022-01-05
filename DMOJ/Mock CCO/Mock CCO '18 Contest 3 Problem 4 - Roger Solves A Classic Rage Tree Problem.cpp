#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 5e4 + 4, LOG = 16;
int N, Q, mx[MM][LOG], mn[MM][LOG+5];

void solve(int tc) {

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> mx[i][0]; mn[i][0] = mx[i][0];
    }
    for (int j = 1; j <= LOG; j++) {
        for (int i = 1; i+(1<<j)-1 <= N; i++) {
            mx[i][j] = max(mx[i][j-1], mx[i+(1<<(j-1))][j-1]);
            mn[i][j] = min(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);
        }
    }
    while (Q--) {
        int x, y; cin >> x >> y;
        int k = log2(y - x + 1);
        int Max = max(mx[x][k], mx[y-(1<<k)+1][k]), Min = min(mn[x][k], mn[y-(1<<k)+1][k]);
        cout << Max - Min << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}