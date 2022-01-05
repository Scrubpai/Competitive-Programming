#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
ll n, k;
void solve(int tc) {
    cin >> k >> n;
    ll ans = 1;
    for (ll i = 1; i <= k; i++) ans *= n;
    cout << ans;
}
int32_t main() {
    //freopen("", "r", stdin); freopen("", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}