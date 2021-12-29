#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
#define nl '\n'
int n, x[MM], pos[MM]; bool vis[MM];
void solve(int tc) {
    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> x[i]; pos[x[i]]++; }
    int mn = 0;
    for (int i = 1; i <= n; ) {
        if (pos[i]) {
            mn++; i += 3;
        } else i++;
    }
    for (int i = 1; i <= n; i++) {
        if (pos[i] && !vis[i-1]) vis[i-1] = 1, pos[i]--;
        if (pos[i] && !vis[i]) vis[i] = 1, pos[i]--;
        if (pos[i] && !vis[i+1]) vis[i+1] = 1;
    }
    int mx = 0;
    for (int i = 0; i <= n+1; i++) {
        if (vis[i]) mx++;
    }
    cout << mn << " " << mx << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}