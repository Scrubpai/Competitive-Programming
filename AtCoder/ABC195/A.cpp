#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int M, H;
void solve(int tc) {
    cin >> M >> H;
    if (H % M == 0) cout << "Yes" << nl;
    else cout << "No" << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }