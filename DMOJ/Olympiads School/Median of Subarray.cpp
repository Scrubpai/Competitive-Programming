#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MM = 1e5 + 5;
int n, a[MM], l; ll ans, bit[2*MM];

void update(int p) {
    for (; p < 2*MM; p += p&-p) bit[p]++;
}
ll query(int p) {
    ll ret = 0;
    for (; p >= 1; p -= p&-p) ret += bit[p];
    return ret;
}

void solve(int tc) {

    cin >> n >> l;
    ll psa = 0; update(MM);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] >= l) a[i] = 1;
        else a[i] = -1;
        psa += a[i];
        ans += query(psa+MM); update(psa+MM);
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}