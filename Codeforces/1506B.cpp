#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n, k; string s;
void solve(int tc) {
    cin >> n >> k >> s;
    vector<int> pos;
    for (int i=0; i<n; i++) {
        if (s[i] == '*') pos.push_back(i);
    }
    int cnt = 1, pre = pos[0];
    if (pos.size()>1) cnt++;
    for (int i=1; i<(int)pos.size(); i++) {
        if (pos[i] - pre > k) cnt++, pre = pos[i-1];
    }
    cout << cnt << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }