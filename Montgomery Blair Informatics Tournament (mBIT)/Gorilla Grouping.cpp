#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MM = 1e5 + 5, MOD = 1e9 + 7;
int n, k, cnt[MM], dsu[MM], a[MM]; ll ans = 1, fib[MM]; unordered_map<int, int> mp; bool vis[MM];

int Find(int x) {
    if (dsu[x] == x) return x;
    else return dsu[x] = Find(dsu[x]);
}

void solve(int tc) {

    cin >> n >> k;
    fib[0] = 1; fib[1] = 2; dsu[1] = 1; cnt[1] = 1;
    for (int i = 2; i <= n; i++) { fib[i] = (fib[i-1] + fib[i-2]) % MOD; dsu[i] = i; cnt[i] = 1; }
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (mp[a[i]-k] != 0) {
            int fu = Find(mp[a[i]-k]), fv = Find(i);
            if (fu != fv) dsu[fu] = fv, cnt[fv] += cnt[fu];
        }
        mp[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        int fu = Find(i);
        if (vis[fu]) continue;
        vis[fu] = 1;
        ans = (ans * 1ll * fib[cnt[fu]] % MOD) % MOD;
    }
    cout << ans - 1 << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}