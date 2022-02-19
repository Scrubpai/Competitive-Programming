#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int a, b, ans; cin >> a >> b; ans = min(b-a, a+(a|b)+1-a-b);
        int cur = 0;
        for (int i=0; i<31; i++) {
            int ta = a;
            if (a&(1<<i)) cur += (1<<i);
            if (b&(1<<i)) {
                if (!(a&(1<<i))) ta-=cur, ta+=(1<<i);
            }
            ans = min(1ll*ans, 1ll*ta + (ta|b) + 1 - a - b);

        }
        int tb = b;
        for (int i=0; i<31; i++) {
            if (!(b&(1<<i)) && a&(1<<i)) {
                tb |= (1<<i);
                int tot = tb - b;
                if (tb == a) ans = min(ans, tot);
                else ans = min(ans, tot + (a|tb) - tb + 1);
            }
            tb &= ~(1<<i);
        }
        cout << ans << '\n';
    }
}