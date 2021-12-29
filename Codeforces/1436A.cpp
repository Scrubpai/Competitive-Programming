#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int n, m, a[105];

void solve(int tc) {

    cin >> n >> m;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum == m) cout << "YES" << nl;
    else cout << "NO" << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}