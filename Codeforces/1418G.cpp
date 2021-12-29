#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);

const int MM = 5e5 + 5;
int n, freq[MM]; ll w[MM], h[MM]; queue<int> idx[MM]; unordered_map<ll, int> mp;

void solve(int tc) {

    cin >> n; mp[0] = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++) w[i] = rng();
    for (int l = 0, r = 1, x; r <= n; r++) {
        cin >> x;
        if (idx[x].size() >= 3) {
            int pre = idx[x].front(); idx[x].pop();
            while (l < pre - 1) { mp[h[l]]--; l++; }
        }
        freq[x] = (freq[x] + 1) % 3;
        h[r] = h[r-1] + w[x];
        if (freq[x] == 0) h[r] -= (3 * w[x]);
        ans += mp[h[r]];
        mp[h[r]]++;
        idx[x].push(r);
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}