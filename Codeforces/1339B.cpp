#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 1e5 + 5;
int n, a[MM];

void solve(int tc) {

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int rit = n / 2, lft = rit -1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) { cout << a[rit] << " "; rit++; }
        else { cout << a[lft] << " "; lft--; }
    }
    cout << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}