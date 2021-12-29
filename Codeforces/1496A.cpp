#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n, k; string s;
void solve(int tc) {
    cin >> n >> k >> s;
    if (!k) { cout << "YES" << nl; return; }
    string rev = s;
    reverse(rev.begin(), rev.end());
    int tmp = n;
    for (int i=0; i<n; i++) {
        if (rev[i] == s[i]) k--, tmp -= 2;
        else {
            if (k!=0) { cout << "NO" << nl; return; }
        }
        if (k==0 && tmp) { cout << "YES" << nl; return; }
    }
    cout << "NO" << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }