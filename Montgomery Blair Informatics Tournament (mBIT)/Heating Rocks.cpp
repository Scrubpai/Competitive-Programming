#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MM = 1e5 + 5;
ll N, T[MM], X, mx, sum;

void solve (int tc) {

    cin >> N >> X;
    for (int i = 1; i <= N; i++) { cin >> T[i]; T[i] = max(X - T[i], 0ll); mx = max(mx, T[i]); sum += T[i]; }
    if (mx >= sum - mx) cout << mx << nl;
    else cout << (sum + 1) / 2 << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}