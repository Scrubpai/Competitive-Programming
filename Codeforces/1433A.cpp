#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

string x;

void solve(int tc) {

    cin >> x;
    int ans = 10 * (((x[0]-'0') % 10) - 1) + (x.size() * (x.size() + 1)) / 2;
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}