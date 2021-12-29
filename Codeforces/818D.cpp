#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 1e5 + 5, MX = 1e6;
#define nl '\n'
int n, A, cnt[MX+5]; bool bad[MX+5];
void solve(int tc) {
    cin >> n >> A;
    for (int i = 1, c; i <= n; i++) {
        cin >> c;
        if (c == A) cnt[c]++;
        else {
            if (bad[c]) continue;
            if (cnt[c] < cnt[A]) bad[c] = 1;
            cnt[c]++;
        }
    }
    for (int i = 1; i <= MX; i++) {
        if (i == A) continue;
        if (cnt[i] >= cnt[A] && !bad[i]) { cout << i << nl; return; }
    }
    cout << -1 << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}