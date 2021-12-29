#include <bits/stdc++.h>
using namespace std;
bool chk(int k, vector<vector<int>> &p) {
    int m = (int)p.size(), n = (int)p[0].size();
    for (int i=0; i<m; i++) {
        int cnt = 0;
        for (int j=0; j<n; j++) {
            if (p[i][j] >= k) cnt++;
        }
        if (cnt >= 2) return 1;
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    for (int tt=0, n, m; tt<t; tt++) {
        cin >> m >> n;
        vector<vector<int>> p(m, vector<int>(n)); vector<int> mx(n);
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cin >> p[i][j];
                mx[j] = max(mx[j], p[i][j]);
            }
        }
        int lo = 1, hi = 1e9, ans = 0;
        for (int i=0; i<n; i++) hi = min(hi, mx[i]);
        while (lo <= hi) {
            int mid = lo+hi>>1;
            if (chk(mid, p)) { ans = max(ans, mid); lo = mid+1; }
            else hi = mid-1;
        }
        cout << ans << '\n';
    }
}