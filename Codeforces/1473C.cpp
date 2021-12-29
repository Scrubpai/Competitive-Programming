#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n, k;
void solve(int tc) {
    cin >> n >> k;
    int m = n - k;
    for (int i = 1; i <= k - m - 1; i++) cout << i << ' ';
    for (int i = k; i >= k - m; i--) cout << i << ' ';
    cout << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}