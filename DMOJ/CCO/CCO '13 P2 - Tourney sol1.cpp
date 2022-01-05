#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define nl '\n'
#define f first
#define s second
int n, m, k; pii t[1<<21]; char op;
void solve(int tc) {
    cin >> n >> m;
    n = 1<<n; k = n-1;
    for (int i=k+1; i<=k+n; i++) {
        cin >> t[i].f;
        t[i].s = i-k;
    }
    for (int i=k; i>=1; i--) {
        t[i] = max(t[2*i], t[2*i+1]);
    }
    for (int i=1, x, y; i<=m; i++) {
        cin >> op;
        if (op == 'W') cout << t[1].s << nl;
        else if (op == 'S') {
            cin >> x;
            int cnt = 0;
            for (int j=(k+x)/2; j>=1; j/=2) {
                if (t[j].s == x) cnt++;
                else break;
            }
            cout << cnt << nl;
        } else {
            cin >> x >> y;
            t[k+x].f = y;
            for (int j=(k+x)/2; j>=1; j/=2) {
                t[j] = max(t[2*j], t[2*j+1]);
            }
        }
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }