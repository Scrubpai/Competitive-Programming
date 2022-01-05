#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
#define nl '\n'
int N, M, a[MM], b[MM], cnt;
void solve(int tc) {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) { cin >> a[i]; if (a[i]) cnt++; }
    for (int i = 1; i <= M; i++) cin >> b[i];
    if (!cnt) { cout << 0 << nl; return; }
    for (int i = 1; i <= M; i++) {
        if (a[b[i]]) cnt--;
        else cnt++;
        a[b[i]] ^= 1;
        if (i >= cnt) { cout << i << nl; return; }
    }
    cnt -= M;
    cout << M + cnt << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc; */ for (int t = 1; t <= tc; t++) solve(t); return 0; }