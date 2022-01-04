#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
#define nl '\n'
struct event { int p, v, op; };
int N; vector<event> line;
void solve(int tc) {
    cin >> N;
    ll lsum = 0, rsum = 0, lft = 0, rit = 0;
    for (int i=1, p, w, d; i<=N; i++) {
        cin >> p >> w >> d;
        line.push_back({max(p-d, 0), w, 0});
        line.push_back({min(p+d, (int)1e9), w, 1});
        rsum += 1ll * max(p-d, 0) * w;
        rit += w;
    }
    sort(line.begin(), line.end(), [](event a, event b) { return a.p < b.p; });
    ll ans = 1e18, pre = 0;
    for (event e : line) {
        if (e.p != pre) ans = min(ans, lsum + rsum);
        lsum += 1ll * (e.p - pre) * lft;
        rsum -= 1ll * (e.p - pre) * rit;
        if (e.op == 0) {
            rit -= e.v;
        } else {
            lft += e.v;
        }
        pre = e.p;
    }
    ans = min(ans, lsum + rsum);
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }