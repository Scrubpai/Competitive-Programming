#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N, K;
void solve(int tc) {
    cin >> N >> K;
    int ans = K;
    for (int i = 2; i <= N; i++) ans *= (K - 1);
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}