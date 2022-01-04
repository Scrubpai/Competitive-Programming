#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 1e5+5;
#define nl '\n'
int L, N, s, t; pii a[MM];
void solve(int tc) {
    cin >> L >> N;
    for (int i=0; i<N; i++) {
        cin >> s >> t; a[i] = {s, t};
    }
    sort(a, a+N);
    int ans = L - a[N-1].second, cur = 0;
    for (int i=0; i<N; i++) {
        if (a[i].first > cur) ans = max(ans, a[i].first - cur);
        cur = max(cur, a[i].second);
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }