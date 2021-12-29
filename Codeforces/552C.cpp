#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
ll w, m;
void solve(int tc) {
    cin >> w >> m;
    vector<ll> res;
    while (m) {
        res.push_back(m%w);
        m/=w;
    }
    int n = res.size(), add = 0;
    for (int i = 0; i < n; i++) {
        res[i] += add; res[i] %= w;
        if (res[i] == 0) continue;
        add = 0;
        if (res[i] != 1 && res[i] != w - 1) { cout << "NO" << nl; return; }
        if (res[i] == w - 1) {
            add = 1;
        }
    }
    cout << "YES" << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}