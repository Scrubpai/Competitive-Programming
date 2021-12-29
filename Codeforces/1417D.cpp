#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;

const int MM = 1e4 + 5;
int n; ll a[MM];

void solve(int tc) {

    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n != 0) { cout << -1 << nl; return; }
    ll cnt = 0;
    for (int i = 2; i <= n; i++) {
        ll x = (i - (a[i] % i)) % i;
        if (x != 0) cnt++;
        cnt++;
    }
    cnt += (n - 1);
    cout << cnt << nl;
    for (int i = 2; i <= n; i++) {
        ll x = (i - (a[i] % i)) % i;
        if (x != 0) cout << 1 << " " << i << " " << x << nl;
        a[i] += x;
        cout << i << " " << 1 << " " << a[i] / i << nl;
    }
    for (int i = 2; i <= n; i++) {
        cout << 1 << " " << i << " " << (sum / n) << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}