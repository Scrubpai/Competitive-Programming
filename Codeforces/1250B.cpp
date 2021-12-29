#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
int n, k, team[8005], cap[8005];
void solve(int tc) {
    cin >> n >> k;
    for (int i = 1, t; i <= n; i++) {
        cin >> t;
        team[t]++;
    }
    sort(team + 1, team + 1 + k);
    cap[1] = team[1];
    for (int i = 1; i <= k; i++) {
        //pair up the first i people, minimum capacity needed
        for (int j = 1; j <= i/2; j++) {
            cap[i] = max(cap[i], team[j] + team[i-j+1]);
        }
    }
    ll ans = 1e18;
    for (int i = (k+1)/2; i <= k; i++) {
        //minimum capacity for i rides
        for (int j = 0; j <= k; j++) {
            //pair the first j people
            if ((j+1)/2 + (k-j) == i) {
                int min_cap = max(cap[j], team[k]);
                ans = min(ans, 1ll*i*min_cap);
            }
        }
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}