#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
ll N, K;
void solve(int tc) {
    cin >> N >> K;
    ll x = N / K;
    cout << min(N - x*K, abs(N - (x+1)*K)) << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}