#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
const int MM = 1e5 + 5;
int N, A[MM], B[MM]; ll ans;
void solve(int tc) {
    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> B[i];
    }
    for (int i = 2; i < N; i++) { A[i] = min(B[i-1], B[i]); ans += A[i]; }
    ans += B[1]; ans += B[N-1];
    cout << ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}