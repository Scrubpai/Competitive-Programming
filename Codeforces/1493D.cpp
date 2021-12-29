#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5, mod = 1e9+7;
#define nl '\n'
int n, q, nxt[MM]; ll ans=1; map<int, int> mp[MM]; multiset<int> st[MM];
void add(int i, int x) {
    while (x > 1) {
        int div = nxt[x], cnt = 0;
        while (nxt[x] == div) cnt++, x /= nxt[x];

        int prevexp = 0;
        if (st[div].size() == n) prevexp = *st[div].begin();
        if (mp[i][div]) st[div].erase(st[div].find(mp[i][div]));
        mp[i][div] += cnt;
        st[div].insert(mp[i][div]);

        if (st[div].size() == n) {
            for (int j=prevexp; j<*st[div].begin(); j++) {
                ans = (ans * div) % mod;
            }
        }
    }
}
void solve(int tc) {
    cin >> n >> q;
    for (int i=2; i<=2e5; i++) {
        if (nxt[i]) continue;
        nxt[i] = i;
        if (i>(int)(sqrt(2e5))) continue;
        for (int j=i*i; j<=2e5; j+=i) nxt[j] = i;
    }
    for (int i=1, a; i<=n; i++) {
        cin >> a;
        add(i, a);
    }
    for (int i=1, j, x; i<=q; i++) {
        cin >> j >> x;
        add(j, x);
        cout << ans << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }