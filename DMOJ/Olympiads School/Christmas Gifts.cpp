#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

struct gift {
    ll p, s, idx;
};
bool cmp(gift a, gift b) { return (a.p + a.s) < (b.p + b.s); }

ll n, b, p[1005], s[1005]; gift a[1005];

void solve(int tc) {

    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> s[i];
        a[i] = {p[i], s[i], i};
    }
    sort(a + 1, a + 1 + n, cmp);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] / 2 + s[i] > b) continue;
        ll cur = b - (p[i] / 2 + s[i]); int cnt = 1;
        for (int j = 1; j <= n; j++) {
            if (a[j].idx == i) continue;
            cur -= (a[j].p + a[j].s);
            if (cur < 0) break;
            cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}