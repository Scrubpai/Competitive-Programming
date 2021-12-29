#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n, k;
void solve(int tc) {
    cin >> n >> k;
    vector<int> ans;
    for (int i=n; i>k; i--) ans.push_back(i);
    for (int i=k-1; i>=(k+1)/2; i--) ans.push_back(i);
    cout << ans.size() << nl;
    for (int x : ans) cout << x << " ";
    cout << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }