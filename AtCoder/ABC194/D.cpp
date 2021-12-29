#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N; double ans;
void solve(int tc) {
    cin >> N;
    for (int i=1; i<N; i++) ans += 1.0*(N)/(N-i);
    cout << fixed << setprecision(6) << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }