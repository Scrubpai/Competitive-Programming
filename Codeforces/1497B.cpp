#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
#define nl '\n'
int n, m;
void solve(int tc) {
    cin >> n >> m;
    vector<int> cnt(m);
    for (int i=0, a; i<n; i++) {
        cin >> a;
        a %= m;
        cnt[a]++;
    }
    int ans = 0;
    if (cnt[0]) ans++;
    for (int i=1; i<=m/2; i++) {
        if (cnt[i] || cnt[m-i]) {
            ans++;
            if (i==m-i || cnt[i]==cnt[m-i]) {
                cnt[i] = cnt[m-i] = 0;
                continue;
            }
            int mn = min(cnt[i], cnt[m-i]);
            if (cnt[i] > cnt[m-i]) {
                cnt[i] -= mn; cnt[m-i] -= mn; cnt[i]--;
                ans += cnt[i];
            } else {
                cnt[i] -= mn; cnt[m-i] -= mn; cnt[m-i]--;
                ans += cnt[m-i];
            }
        }
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }