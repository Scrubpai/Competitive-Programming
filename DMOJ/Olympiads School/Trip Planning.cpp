#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
double A, B, C;
void solve(int tc) {
    cin >> A >> B >> C;
    double ans = 60 * (A/40000 + B/60000 + C/70000);
    cout << fixed << setprecision(2) << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }