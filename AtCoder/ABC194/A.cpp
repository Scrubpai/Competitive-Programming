#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int A, B;
void solve(int tc) {
    cin >> A >> B;
    if (A+B >= 15 && B >= 8) cout << 1 << nl;
    else if (A+B >= 10 && B >= 3) cout << 2 << nl;
    else if (A+B >= 3) cout << 3 << nl;
    else cout << 4 << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }