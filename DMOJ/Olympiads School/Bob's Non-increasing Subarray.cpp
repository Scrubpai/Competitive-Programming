#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
#define nl '\n'
int N, a[MM];
void solve(int tc) {
    cin >> N;
    int ans = 1, len = 0;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        if (a[i] <= a[i-1]) len++;
        else len = 1;
        ans = max(ans, len);
    }
    cout << ans << nl;
}
int32_t main() {
    //freopen("", "r", stdin); freopen("", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}