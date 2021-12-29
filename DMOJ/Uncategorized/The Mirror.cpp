#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
bool prime(int x) {
    if (x == 1) return false;
    for (int i=2; i<=sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}
void solve(int tc) {
    int N; cin >> N;
    for (int i=0, l, r; i<N; i++) {
        cin >> l >> r;
        int ans = 0;
        for (int j=l; j<r; j++) {
            if (prime(j)) ans++;
        }
        cout << ans << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }