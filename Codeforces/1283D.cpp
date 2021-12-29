#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 2e5 + 5;
#define nl '\n'
int n, m, x[MM], cnt[MM], cnt2[MM]; vector<pi> d;
void solve(int tc) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> x[i];
    sort(x + 1, x + 1 + n);
    for (int i = 1; i < n; i++) {
        if (x[i] == x[i+1]) continue;
        int mid = (x[i] + x[i+1]) / 2;
        int dist = min(m, mid-x[i]);
        d.push_back({dist, i});
        cnt[1]+=2; cnt[dist]-=2;
        if (dist == x[i+1] - mid) cnt[dist]++, cnt[dist+1]--;
        else cnt[dist]+=2, cnt[dist+1]-=2;
    }
    ll ans = 0;
    int tmp = m, i;
    for (i = 1; i <= m; i++) {
        cnt[i] += cnt[i-1];
        cnt2[i] += min(tmp, cnt[i]);
        ans += 1ll*i*min(tmp, cnt[i]);
        tmp -= cnt[i];
        if (tmp <= 0) break;
        cnt2[i] += min(tmp, 2);
        ans += 1ll*i*min(tmp, 2);
        tmp -= 2;
        if (tmp <= 0) break;
    }
    cout << ans << nl;
    sort(d.rbegin(), d.rend());
    for (int j = 1; j <= i; j++) {
        if (cnt2[j]) { cnt2[j]--; cout << x[1]-j << ' ';}
        if (cnt2[j]) { cnt2[j]--; cout << x[n]+j << ' ';}
        if (!cnt2[j]) continue;
        for (pi p : d) {
            cout << x[p.second] + j << ' ';
            cnt2[j]--;
            if (!cnt2[j]) break;
            if (x[p.second+1] - j != x[p.second] + j) {
                cout << x[p.second+1] - j << ' ';
                cnt2[j]--;
                if (!cnt2[j]) break;
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}