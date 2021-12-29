#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
string a, b;
void solve(int tc) {
    cin >> a >> b;
    int n = a.size(), m = b.size(), ans = n + m;
    for (int i=1; i<=n; i++) {
        for (int j=0; j+i-1<n; j++) {
            if (b.find(a.substr(j, i)) != -1) ans = min(ans, n+m-2*i);
        }
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }