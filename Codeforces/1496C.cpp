#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
#define nl '\n'
int n;
void solve(int tc) {
    cin >> n;
    deque<int> x, y;
    for (int i=0, a, b; i<2*n; i++) {
        cin >> a >> b;
        if (b==0) x.push_back(abs(a));
        else y.push_back(abs(b));
    }
    sort(x.begin(), x.end()); sort(y.begin(), y.end());
    double ans = 0;
    for (int i=0; i<n; i++) {
        ans += sqrt(1ll*x.front()*x.front() + 1ll*y.front()*y.front());
        x.pop_front(); y.pop_front();
    }
    cout << fixed << setprecision(18) << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }