#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
typedef long long ll;
int n, m, pre; string s, t; vector<int> idx[26]; ll ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> s >> t;
    for (int i=0; i<n; i++) idx[s[i]-'a'].push_back(i);
    for (int i=0; i<m; i++) {
        int p = t[i]-'a';
        if (idx[p].empty()) { cout << -1 << '\n'; return 0; }
        if (pre > idx[p].back()) ans += n - pre, pre = 0;
        int x = lower_bound(idx[p].begin(), idx[p].end(), pre) - idx[p].begin();
        ans += idx[p][x] - pre + 1; pre = idx[p][x] + 1;
    }
    cout << ans << '\n';
}