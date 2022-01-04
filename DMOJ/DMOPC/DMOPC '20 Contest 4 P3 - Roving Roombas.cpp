#include <bits/stdc++.h>
using namespace std;
const int MM = 4e5+5;
typedef long long ll;
typedef pair<ll, ll> pll;
#define nl '\n'
#define f first
#define s second
ll N, M, bit[MM]; vector<pll> roombas, cords; vector<ll> comp;
void update(int p) { for (; p <= comp.size(); p +=p&-p) bit[p]++; }
ll query(int p) { ll ret = 0; for (; p >= 1; p -= p&-p) ret += bit[p]; return ret;}
void solve(int tc) {
    cin >> N >> M; comp.push_back(-1);
    for (int i=0, x, y; i<N; i++) {
        cin >> x >> y;
        comp.push_back(y);
        roombas.emplace_back(make_pair(x, y));
    }
    for (int i=0, x, y; i<M; i++) {
        cin >> x >> y;
        comp.push_back(y);
        cords.emplace_back(make_pair(x, y));
    }
    sort(comp.begin(), comp.end()); comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    sort(roombas.begin(), roombas.end()); sort(cords.begin(), cords.end());
    ll ans = 0;
    for (int i=0, j=0; i<N; i++) {
        while (j<M && cords[j].f <= roombas[i].f) {
            int idx = lower_bound(comp.begin(), comp.end(), cords[j].s) - comp.begin();
            update(idx);
            j++;
        }
        int idx = lower_bound(comp.begin(), comp.end(), roombas[i].s) - comp.begin();
        ans += j - query(idx-1);
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }