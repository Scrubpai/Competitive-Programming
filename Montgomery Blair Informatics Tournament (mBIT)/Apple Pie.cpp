#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int K, M, N;

void solve(int tc) {

    cin >> K >> M >> N;
    if (N >= 10 * K) cout << 0 << nl;
    else cout << (10 * K - N + M - 1) / M << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}