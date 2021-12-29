#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5 + 5;
#define nl '\n'
int N, M, A[MM]; ll ans;
void solve(int tc) {
    cin >> N >> M;
    int k = 1e9, pre = 0;
    for (int i = 1; i <= M; i++) cin >> A[i];
    sort(A + 1, A + 1 + M);
    A[M+1] = N + 1;
    for (int i = 1; i <= M + 1; i++) {
        if (A[i] - pre - 1 != 0) k = min(k, A[i] - pre - 1);
        pre = A[i];
    }
    pre = 0;
    for (int i = 1; i <= M + 1; i++) {
        ans += 1ll * (A[i] - pre - 1 + k - 1) / k;
        pre = A[i];
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}