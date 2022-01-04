#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define INF 0x3f3f3f3f

const int MM = 1e5 + 5;
int n, m, l[MM], r[MM];

bool check(int d) {
    int i = 1, j = 1;
    for (; j <= m; j++) {
        if(i > n) break;
        if (abs(r[j] - l[i]) <= d) i++;
    }
    if (i <= n) return 0;
    return 1;
}

void solve(int tc) {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= m; i++) cin >> r[i];
    sort(l + 1, l + 1 + n); sort(r + 1, r + 1 + m);
    if (n > m) { swap(n, m); swap(l, r); }
    int lo = 0, hi = 1e9, ans = INF;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid - 1, ans = min(ans, mid);
        else lo = mid + 1;
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}