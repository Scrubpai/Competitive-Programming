#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
#define f first
#define s second
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    for (int tt=0, n; tt<t; tt++) {
        cin >> n; vector<int> k(n), h(n); vector<pi> intervals;
        for (int i=0; i<n; i++) cin >> k[i];
        for (int i=0; i<n; i++) { cin >> h[i]; intervals.push_back({k[i]-h[i], k[i]}); }
        sort(intervals.begin(), intervals.end());
        ll l=-1, r=-1, ans=0;
        for (pi p : intervals) {
            if (p.f >= r) {
                ans += (r-l) * (r-l+1) / 2;
                l = p.f; r = p.s;
            } else {
                r = max(r, p.s);
            }
        }
        ans += (r-l) * (r-l+1) / 2;
        cout << ans << '\n';
    }
}