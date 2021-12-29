#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n, M, T;
void solve(int tc) {
    cin >> n >> M >> T;
    int pre = 0, N = n;
    for (int i = 1, a, b; i <= M; i++) {
        cin >> a >> b;
        N -= (a - pre);
        if (N <= 0) { cout << "No" << nl; return; }
        N += (b - a);
        N = min(N, n);
        pre = b;
    }
    N -= (T - pre);
    if (N <= 0) cout << "No" << nl;
    else cout << "Yes" << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}