#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
#define nl '\n'
ll N, h[MM], w[MM];
int main() {
    cin >> N;
    ll ans = 0, add = 0;
    for (int i=1; i<=N+1; i++) cin >> h[i];
    for (int i=1; i<=N; i++) {
        cin >> w[i];
        ll tmp = 1ll * (h[i] + h[i+1]) * w[i];
        if (tmp % 2 == 1) add++;
        ans += tmp/2;
        if (add == 2) ans++, add = 0;
    }
    cout << ans;
    if (add) cout << ".5" << nl;
    return 0;
}