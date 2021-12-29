#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 1e5 + 5;
int n, a[MM];

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n % 2 == 1) {
        cout << "YES" << nl << n - 2 << nl;
        for (int i = 3; i <= n; i += 2) cout << i << " " << i - 1 << " " << i - 2 << nl;
        for (int i = n - 3; i >= 1; i -= 2) cout << i << " " << i - 1 << " " << n << nl;
    } else {
        int tot = 0;
        for (int i = 1; i <= n; i++) tot ^= a[i];
        if (tot != 0) cout << "NO" << nl;
        else {
            cout << "YES" << nl << n - 3 << nl;
            for (int i = 3; i < n; i += 2) cout << i << " " << i - 1 << " " << i - 2 << nl;
            for (int i = n - 1 - 3; i >= 1; i -= 2) cout << i << " " << i - 1 << " " << n - 1 << nl;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}