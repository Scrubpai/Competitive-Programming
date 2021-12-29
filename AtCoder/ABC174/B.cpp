#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
int n, d;
void solve(int tc) {
    cin >> n >> d;
    int ans = 0;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        if (1ll * x * x + 1ll * y * y <= 1ll * d * d) ans++;
    }
    cout << ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}