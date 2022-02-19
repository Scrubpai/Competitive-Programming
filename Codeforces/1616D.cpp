#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; vector<int> a(n), select(n+1, 1); vector<ll> psa(n+1);
        for (int i=0; i<n; i++) cin >> a[i];
        int x; cin >> x;
        for (int i=0; i<n; i++) { a[i]-=x; psa[i+1]=psa[i]+a[i]; }
        ll cur = 0;
        for (int i=2; i<=n; i++) {
            if (psa[i] < cur) select[i]=0, cur=psa[i], i++;
            else cur = max(cur, psa[i-1]);
        }
        cur = psa[n];
        for (int i=n; i>=1; ) {
            while (!select[i] && i>0) i--, cur=psa[i], i--;
            if (i==n) { i--; continue; }
            if (cur < psa[i-1]) select[i]=0, i--, cur=psa[i], i--;
            else cur = max(cur, psa[i]), i--;
        }
        int ans = 0;
        for (int i=1; i<=n; i++) ans += select[i];
        cout << ans << '\n';
    }
}