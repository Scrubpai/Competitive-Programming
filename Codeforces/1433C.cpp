#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 3e5 + 5;
int n, a[MM];

void solve(int tc) {

    int mx = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == mx) {
            if (i > 1 && a[i] > a[i-1]) { cout << i << nl; return; }
            if (i < n && a[i] > a[i+1]) { cout << i << nl; return; }
        }
    }
    cout << -1 << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}