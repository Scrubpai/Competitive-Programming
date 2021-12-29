#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 2e5+5;
#define nl '\n'
#define f first
#define s second
int n;
void solve(int tc) {
    cin >> n;
    vector<pii> p(n);
    for (int i=0; i<n; i++) cin >> p[i].f;
    for (int i=0; i<n; i++) cin >> p[i].s;
    sort(p.begin(), p.end());
    ll ans = 0, pr = 1, pc = 1;
    for (int i=0; i<n; i++) {
        if (p[i].f == pr && p[i].s == pc) continue;
        ll x = p[i].s - pc;
        if (x == p[i].f - pr) {
            if ((pr + pc) % 2 == 0) ans += x;
        } else {
            if ((pr + pc) % 2 == 0) pr++;
            pr += x; pc += x;
            x = p[i].f - pr;
            if ((pr+pc) % 2 == 0) x--;
            ans += (x+1)/2;
        }
        pr = p[i].f; pc = p[i].s;
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }