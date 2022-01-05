#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MM = 1e6 + 5;
int n, a[MM];

void solve(int tc) {

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    if (n % 2 == 1) cout << 0 << nl;
    else cout << a[n/2] - a[n/2-1] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1;// cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}