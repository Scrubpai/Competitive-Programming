#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
typedef long long ll;

const int MM = 5e5 + 5;
int n, s[MM], mx1[MM], mx2[MM]; ll ans = LL_INF, inc[MM], decre[MM];

void solve(int tc) {

    cin >> n; s[0] = s[n+1] = -LL_INF;  ms(mx1, -LL_INF); ms(mx2, -LL_INF);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        mx1[i] = max(mx1[i-1], s[i]);
        if (s[i] >= mx1[i]) inc[i] = inc[i-1];
        else inc[i] = inc[i-1] + (mx1[i] - s[i]);
    }
    for (int i = n; i >= 1; i--) {
        mx2[i] = max(mx2[i+1], s[i]);
        if (s[i] >= mx2[i]) decre[i] = decre[i+1];
        else decre[i] = decre[i+1] + (mx2[i]-s[i]);
    }
    for (int i = 1; i <= n; i++) {
        ans = min(ans, inc[i-1] + decre[i+1] + max(inc[i] - inc[i-1], decre[i] - decre[i+1]));
    }
    cout << nl;
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}