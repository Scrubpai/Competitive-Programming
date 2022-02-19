#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; vector<int> cnt(101);
        for (int i=0, x; i<n; i++) {
            cin >> x;
            cnt[abs(x)]++;
        }
        int ans = min(cnt[0], 1);
        for (int i=1; i<=100; i++) {
            ans += min(cnt[i], 2);
        }
        cout << ans << '\n';
    }
}