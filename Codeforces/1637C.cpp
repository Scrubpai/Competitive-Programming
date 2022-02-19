#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; vector<int> a(n);
        ll ans = 0, cnt0 = 0, cnt1 = 0, tmp = 0;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            if (i==0 || i==n-1) continue;
            ans += (a[i]+1)/2;
            if (a[i] >= 2) cnt0++, tmp = a[i];
            else cnt1++;
        }
        if (cnt0==0 || (cnt0==1 && tmp%2==1 && !cnt1)) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}