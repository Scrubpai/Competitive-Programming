#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define nl '\n'

const int MM = 1e5 + 5; const ll INF = 1e9;
ll N, D, x[MM];

void solve(int tc) {

    cin >> N >> D;
    for (int i = 1; i <= N; i++) cin >> x[i];
    ll lo1 = INF, hi1 = -INF, lo2 = INF, hi2 = -INF, mn = INF, mx = -INF;
    for (int i = 1, p1, p2; i <= D; i++) {
        cin >> p1 >> p2;
        if (x[p2] > x[p1]) lo1 = min(lo1, x[p1]), hi1 = max(hi1, x[p2]);
        else if (x[p2] < x[p1]) lo2 = min(lo2, x[p2]), hi2 = max(hi2, x[p1]);
        mn = min({mn, x[p1], x[p2]}); mx = max({mx, x[p1], x[p2]});
    }
    if (lo1 == INF || lo2 == INF) cout << mx - mn << nl;
    else cout << min(1ll * (mx - lo1) + 1ll * (mx - lo2), 1ll * (hi2 - mn) + 1ll * (hi1 - mn)) << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}