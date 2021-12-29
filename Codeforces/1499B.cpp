#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
string s;
void solve(int tc) {
    cin >> s;
    int n = s.size(), mx = n;
    for (int i=1; i<n; i++) {
        if (s[i] == '1' && s[i-1] == '1') {
            mx = i; break;
        }
    }
    for (int i=mx+1; i<n; i++) {
        if (s[i] == '0' && s[i-1] == '0') {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }