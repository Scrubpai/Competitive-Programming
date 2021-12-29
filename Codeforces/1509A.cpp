#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+5;
#define nl '\n'
int n, a[MM];
void solve(int tc) {
    cin >> n;
    vector<int> odd, even;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i]&1) odd.push_back(i);
        else even.push_back(i);
    }
    for (int v : odd) cout << v << ' ';
    for (int v : even) cout << v << ' ';
    cout << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }