#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int n;

void solve(int tc) {

    cin >> n;
    for (int i = 0; i <= n / 7; i++) {
        for (int j = 0; j <= (n - 7 * i) / 5; j++) {
            int k = (n - 7 * i - 5 * j) / 3;
            if (7 * i + 5 * j + 3 * k == n) {
                cout << k << " " << j << " " << i << nl;
                return;
            }
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