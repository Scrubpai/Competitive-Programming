#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
#define nl '\n'
int n, m, k, cow[MM], t[MM];
bool check(int lmt) {
    int cnt = 0;
    for (int i=1, j=1; j<=m; j++) {
        while (i <= n && t[j] <= cow[i] && t[j] >= cow[i]-k && cnt<lmt) i++, cnt++;
        cnt = 0;
        if (i>n) return 1;
    }
    return 0;
}
void solve(int tc) {
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) cin >> cow[i];
    for (int i=1; i<=m; i++) cin >> t[i];
    sort(cow+1, cow+1+n); sort(t+1, t+m+1);
    int lo=1, hi=n, ans=n+1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) { ans = mid; hi = mid-1; }
        else lo = mid+1;
    }
    cout << (ans > n ? -1 : ans) << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }