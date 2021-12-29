#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

ll l, r, x, y;

void solve(int tc) {

    cin >> l >> r;
    if (2 * l > r) cout << -1 << " " << -1 << nl;
    else cout << l << " " << 2 * l << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}