#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int x, y, g; string x1[MM], x2[MM], ya[MM], yb[MM]; unordered_map<string, int> mp;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> x;
    for (int i=1; i<=x; i++) {
        cin >> x1[i] >> x2[i];
    }
    cin >> y;
    for (int i=1; i<=y; i++) {
        cin >> ya[i] >> yb[i];
    }
    cin >> g;
    for (int i=1; i<=g; i++) {
        string a, b, c; cin >> a >> b >> c;
        mp[a] = mp[b] = mp[c] = i;
    }
    int ans = 0;
    for (int i=1; i<=x; i++) {
        if (mp[x1[i]] != mp[x2[i]]) ans++;
    }
    for (int i=1; i<=y; i++) {
        if (mp[ya[i]] == mp[yb[i]]) ans++;
    }
    cout << ans << '\n';
}