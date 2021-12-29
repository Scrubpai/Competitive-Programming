#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
const int MM = 1e6 + 5;
int n, p[MM]; bool vis[MM], res;
void solve(int tc) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            res ^= 1;
            for (int j = i; ; j = p[j]) {
                if (vis[j]) break;
                vis[j] = 1;
            }
        }
    }
    if ((n-res)%2 == (3*n) % 2) cout << "Petr" << nl;
    else cout << "Um_nik" << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}