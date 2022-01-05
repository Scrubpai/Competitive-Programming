#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;

const int MM = 1e6 + 5;
int n; string s; ll base = 131;

void solve(int tc) {

    cin >> s; n = s.size(); s = " " + s;
    ll h1 = 0, h2 = 0, p = 1; int ans = 1;
    for (int l = 1, r = n; l < r; l++, r--) {
        h1 = h1 * base + s[l];
        h2 = h2 + p * s[r];
        p *= base;
        if (h1 == h2) {
            h1 = 0; h2 = 0; p = 1; ans += 2;
            if (l == r - 1) ans--;
        }
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}