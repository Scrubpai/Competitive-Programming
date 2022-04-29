#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
typedef long long ll;
int N, M, ans[MM]; ll K;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M >> K;
    if (K<N) { cout << -1 << '\n'; return 0; }
    for (int i=1; i<=N; i++) {
        int val = min(i, M);
        if (K-val-(N-i) >= 0) ans[i] = ((i-1)%M)+1, K -= val;
        else {
            if (K == N-i+1) ans[i] = ans[i-1], K--;
            else {
                int rem = N-i; ll need = K-rem;
                assert(need > 0 && need < M);
                ans[i] = ans[i-need]; K -= need;
            }
        }
    }
    if (K) { cout << -1 << '\n'; return 0; }
    cout << ans[1];
    for (int i=2; i<=N; i++) cout << " " << ans[i];
}