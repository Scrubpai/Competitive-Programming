#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
#define INF 0x3f3f3f3f

int n;

void solve(int tc) {

    cin >> n; int ans = INF;
    if (n == 1) { cout << 0 << nl; return; }
    for (int i = 1; i <= sqrt(n); i++) {
        int moves = (i - 1) + ((n - i) / i);
        if ((n - i) % i != 0) moves++;
        ans = min(ans, moves);
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);

    return 0;
}