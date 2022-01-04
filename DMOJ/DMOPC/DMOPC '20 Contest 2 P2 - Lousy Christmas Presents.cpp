#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))
#define INF 0x3f3f3f3f

const int MM = 1e5 + 5, MX = 1e6 + 5;
int n, m, c[MM], a[MX], b[MX], ans = 0;

void solve(int tc) {

    cin >> n >> m;
    ms(a, INF);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        a[c[i]] = min(a[c[i]], i);
        b[c[i]] = max(b[c[i]], i);
    }
    for (int i = 1, c1, c2; i <= m; i++) {
        cin >> c1 >> c2;
        ans = max(ans, b[c2] - a[c1] + 1);
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}