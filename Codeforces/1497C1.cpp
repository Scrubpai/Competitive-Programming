#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n, k;
void solve(int tc) {
    cin >> n >> k;
    if (n % 2 == 1) {
        cout << 1 << " " << (n-1)/2 << " " << (n-1)/2 << nl;
    } else {
        if ((n-2)%4==0) cout << 2 << " " << (n-2)/2 << " " << (n-2)/2 << nl;
        else {
            int m = n/4;
            cout << m << " " << m << " " << 2*m << nl;
        }
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }