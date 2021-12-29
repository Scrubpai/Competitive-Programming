#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long MAXN = numeric_limits<long long>::max();
typedef long long ll;

int t, a, b, x, y; int a1, a2;

void solve() {

    cin >> t;
    for (int i=0; i<t; i++) {
        int ans = 0;
        cin >> a >> b >> x >> y;
        x++; y++;
        a1 = max(a*(y-1), a*(b-y)); a2 = max(b*(x-1), b*(a-x));
        ans = max(a1, a2);
        cout << ans << "\n";
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
