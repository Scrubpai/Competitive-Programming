#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n;
void solve(int tc) {
    cin >> n;
    vector<int> a(n); map<int, int> mp;
    int mx = 0, sum = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        mx = max(mx, mp[a[i]]);
    }
    for (auto i : mp) sum += i.second;
    sum -= mx;
    if (sum >= mx) cout << n % 2 << nl;
    else cout << mx - sum << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }