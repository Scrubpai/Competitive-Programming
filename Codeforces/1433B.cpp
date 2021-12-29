#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int n, a[51];

void solve(int tc) {

    cin >> n;
    int pre = -1, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (!a[i]) continue;
        if (pre == -1) pre = i;
        else ans += i - pre - 1, pre = i;
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