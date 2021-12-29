#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
typedef long long ll;
#define nl '\n'
ll n, k, h, a;
void solve(int tc) {
    cin >> n >> h >> k;
    ll rem = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (rem + a <= h) rem += a;
        else ans++, rem = a;
        ans += rem/k; rem %= k;
    }
    ans += (rem + k - 1) / k;
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}