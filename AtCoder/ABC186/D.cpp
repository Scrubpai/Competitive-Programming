#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
typedef long long ll;
#define nl '\n'
int N, A[MM]; ll ans, psa[MM];
void solve(int tc) {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    sort(A + 1, A + 1 + N);
    for (int i = 1; i <= N; i++) psa[i] = psa[i-1] + A[i];
    for (int i = 1; i < N; i++) {
        ans += psa[N] - psa[i] - 1ll*(N-i)*A[i];
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}