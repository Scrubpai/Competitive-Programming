#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
#define nl '\n'
int N, psa[MM]; string s;
void solve(int tc) {
    cin >> N >> s; s = " " + s;
    for (int i = 1; i <= N; i++) {
        if (s[i] == 'W') psa[i] = 1;
        psa[i] += psa[i-1];
    }
    //only possible arrangement: RRR... WWW...
    int ans = 1e9;
    for (int i = 1; i <= N; i++) {
        //consider position i as the leftmost white
        ans = min(ans, max(psa[i-1], (N - i) - (psa[N] - psa[i])));
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}