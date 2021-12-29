#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n; string s;
void solve(int tc) {
    cin >> n >> s;
    if (n % 3 != 0) { cout << "NO" << nl; return; }
    int cnt = 0, m = 0, t = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'T') cnt++, t++;
        else cnt--, m++;
        if (cnt<0) { cout << "NO" << nl; return; }
    }
    if (m != n/3 || 2*t == m) { cout << "NO" << nl; return; }
    cnt = 0;
    for (int i=n-1; i>=0; i--) {
        if (s[i] == 'T') cnt++;
        else cnt--;
        if (cnt < 0) { cout << "NO" << nl; return; }
    }
    cout << "YES" << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }