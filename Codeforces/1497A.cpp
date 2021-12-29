#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n;
void solve(int tc) {
    cin >> n;
    vector<int> a(n), b, c, vis(105);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (!vis[a[i]]) {
            vis[a[i]] = 1;
            b.push_back(a[i]);
        } else {
            c.push_back(a[i]);
        }
    }
    sort(b.begin(), b.end());
    for (int i=0; i<(int)b.size(); i++) cout << b[i] << ' ';
    for (int i=0; i<(int)c.size(); i++) cout << c[i] << ' ';
    cout << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }