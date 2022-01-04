#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N, P[1005], K[1005], diff[1005];
void solve(int tc) {
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++) cin >> P[i];
    for (int i = 1; i <= N; i++) {
        cin >> K[i];
        diff[i] = K[i] - P[i];
        if (diff[i] > 0) {
            if (diff[i-1] > 0) ans += max(0, diff[i] - diff[i-1]);
            else ans += diff[i];
        } else {
            if (diff[i-1] < 0) ans += max(0, diff[i-1] - diff[i]);
            else ans += -diff[i];
        }
    }
    cout << ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}