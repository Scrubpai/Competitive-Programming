#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
#define nl '\n'
int N, P[MM], W[MM], D[MM];
ll get(ll c) {
    ll ret = 0;
    for (int i=1; i<=N; i++) {
        if (c < P[i] - D[i]) ret += 1ll * W[i] * (P[i] - D[i] - c);
        else if (c > P[i] + D[i]) ret += 1ll * W[i] * (c - (P[i] + D[i]));
    }
    return ret;
}
void solve(int tc) {
    cin >> N;
    vector<int> p;
    for (int i=1; i<=N; i++) {
        cin >> P[i] >> W[i] >> D[i];
        p.push_back(max(0, P[i] - D[i])); p.push_back(min((int)1e9, P[i]+D[i]));
    }
    sort(p.begin(), p.end()); p.resize(unique(p.begin(), p.end()) - p.begin());
    ll ans = 1e18, lo = 0, hi = p.size()-1;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ans = min(ans, get(p[mid]));
        if (get(p[mid+1]) > get(p[mid])) hi = mid - 1;
        else lo = mid + 1;
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }