#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
ll L; bool vis[13];
void solve(int tc) {
    cin >> L; L--; //cut at position 0 < p < L
    ll ans = 1;
    for (ll i = 0; i < 11; i++) {
        ans = ans * (L - i);
        for (ll j = 1; j <= 11; j++) {
            if (vis[j]) continue;
            if (ans % j == 0) ans /= j, vis[j] = 1;
        }
    }
    cout << ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}