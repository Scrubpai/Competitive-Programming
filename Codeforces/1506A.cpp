#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
ll n, m, x;
void solve(int tc) {
    cin >> n >> m >> x;
    x--;
    ll r = x % n, c = x / n;
    cout << r * m + c + 1 << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }