#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e7;
#define nl '\n'
int t, c, d, x, mind[MM+5], num[MM+5], p[10];
void solve(int tc) {
    cin >> t;
    for (int i=2; i<=MM; i++) {
        if (!mind[i]) {
            for (int j=i; j<=MM; j+=i) {
                if (!mind[j]) mind[j] = i;
            }
        }
        int j = i/mind[i];
        num[i] = num[j] + (mind[i] != mind[j]);
    }
    while (t--) {
        cin >> c >> d >> x;
        int ans = 0;
        for (int i=1; i<=(int)sqrt(x); i++) {
            if (x % i == 0) {
                int g = i;
                if (((x/g)+d)%c == 0) {
                    int k = ((x/g)+d)/c;
                    ans += (1 << num[k]);
                }
                if (g != x/i) {
                    g = x/i;
                    if (((x/g)+d)%c==0) {
                        int k = ((x/g)+d)/c;
                        ans += (1 << num[k]);
                    }
                }
            }
        }
        cout << ans << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }