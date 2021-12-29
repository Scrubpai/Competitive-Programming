#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N, K, X, Y;
void solve(int tc) {
    cin >> N >> K >> X >> Y; K = min(K, N);
    cout << X * K + (N - K) * Y << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}