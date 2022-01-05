#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;
#define nl '\n'
int N, a[MM][MM];
void rotate() {
    for (int i=0; i<N/2; i++) {
        for (int j=0; j<N; j++) {
            swap(a[i][j], a[N-i-1][j]);
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            swap(a[i][j], a[j][i]);
        }
    }
}
int solve() {
    int sum = 0;
    for (int i=0; i<N; i++) {
        int cur1 = 0, cur2 = 0;
        for (int j=0; j<N; j+=2) {
            cur1 += a[i][j];
        }
        for (int j=1; j<N; j+=2) {
            cur2 += a[i][j];
        }
        sum += max(cur1, cur2);
    }
    return sum;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> a[i][j];
        }
    }
    int ans = solve();
    rotate();
    ans = max(ans, solve());
    cout << ans << nl;
    return 0;
}