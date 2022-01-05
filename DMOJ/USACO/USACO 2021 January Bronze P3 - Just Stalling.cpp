#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
int N, a[25], b[25];
void solve(int tc) {
    cin >> N;
    for (int i=0; i<N; i++) cin >> a[i];
    for (int i=0; i<N; i++) cin >> b[i];
    sort(a, a+N, greater<int>()); sort(b, b+N, greater<int>());
    ll ans = 1;
    for (int i=0, j=0; i<N; i++) {
        while (j<N && b[j] >= a[i]) j++;
        ans *= (j - i);
        ans = max(ans, 0ll);
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }