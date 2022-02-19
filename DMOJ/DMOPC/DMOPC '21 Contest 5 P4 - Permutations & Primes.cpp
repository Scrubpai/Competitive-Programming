#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
bool chk(int x) {
    for (int i=2; i*i<=x; i++) {
        if (x%i==0) return 0;
    }
    return 1;
}
void solve(int n) {
    if (n == 1) cout << 1 << '\n';
    else if (n == 2 || n == 3) cout << -1 << '\n';
    else if (n == 4) cout << 3 << ' ' << 1 << ' ' << 4 << ' ' << 2 << '\n';
    else if (n == 5) cout << 5 << ' ' << 3 << ' ' << 1 << ' ' << 4 << ' ' << 2 << '\n';
    else if (n == 6) cout << 6 << ' ' << 3 << ' ' << 5 << ' ' << 2 << ' ' << 4 << ' ' << 1 << '\n';
    else if (n == 7) cout << 7 << ' ' << 5 << ' ' << 3 << ' ' << 1 << ' ' << 6 << ' ' << 4 << ' ' << 2 << '\n';
    else {
        for (int i=2; i<=n-(n&1); i++) {
            if (chk(i) && chk(n-i-(n&1))) {
                cout << 1;
                for (int j=1; j<n-(n&1); j++) {
                    cout << ' ' << (1ll*j*i)%(n-(n&1))+1;
                }
                if (n&1) cout << ' ' << n;
                cout << '\n';
                return;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t, n; cin >> t; while(t--) { cin >> n; solve(n); }
}