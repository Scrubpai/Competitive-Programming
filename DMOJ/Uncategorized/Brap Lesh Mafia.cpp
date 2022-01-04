#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

ll n, k, a, b;

void solve(int tc) {

    cin >> n >> k;
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        tot += (a * b) % k;
    }
    ll d = tot / k;
    cout << (tot - d * k + k) % k << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}