#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
#define nl '\n'
int N, M, h[MM];
void solve(int tc) {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> h[i];
    sort(h + 1, h + 1 + N);
    for (int i = 1, t; i <= M; i++) {
        cin >> t;
        int idx = lower_bound(h + 1, h + 1 + N, t) - (h + 1) + 1;
        cout << M - idx + 1 << nl;
    }
}
int32_t main() {
    //freopen("", "r", stdin); freopen("", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}