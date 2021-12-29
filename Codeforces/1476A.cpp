#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
ll n, k;
void solve(int tc) {
    cin >> n >> k;
    if (k < n) {
        ll x = (n + k - 1) / k;
        k *= x;
    }
    cout << (k + n - 1) / n << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }