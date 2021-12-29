#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5 + 5;
#define nl '\n'
int N, a[MM], b[MM], pa[MM], pb[MM], rot[MM];
void solve(int tc) {
    cin >> N;
    for (int i = 0; i < N; i++) { cin >> a[i]; a[i]--; pa[a[i]] = i; }
    for (int i = 0; i < N; i++) { cin >> b[i]; b[i]--; pb[b[i]] = i; }
    ll ans = 1e18, d = 0, change = 0;
    for (int i = 0; i < N; i++) {
        d += abs(pa[i] - pb[i]);
        if (pb[i] < pa[i]) change--;
        else change++;
        rot[(pa[i]-pb[i]+N)%N]++;
    }
    for (int i = 0; i < N; i++) { //simulate rotations
        ans = min(ans, d);
        d = d + change - 1 + (pa[b[N-i-1]] - 0) - (N - 1 - pa[b[N-i-1]]);
        change += 1ll*2*rot[i+1]-2;
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}