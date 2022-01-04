#include <bits/stdc++.h>
using namespace std;
const int MM = 5e6+5;
#define nl '\n'
int M, N, K, r[MM], c[MM];
int main() {
    cin >> M >> N >> K;
    for (int i=1, v; i<=K; i++) {
        char op; cin >> op >> v;
        if (op == 'R') r[v]++;
        else c[v]++;
        r[v]%=2; c[v]%=2;
    }
    int cnt = 0;
    for (int i=1; i<=M; i++) {
        if (!r[i]) cnt++;
    }
    int ans = 0;
    for (int i=1; i<=N; i++) {
        if (c[i]) ans += cnt;
        else ans += M-cnt;
    }
    cout << ans << nl;
    return 0;
}