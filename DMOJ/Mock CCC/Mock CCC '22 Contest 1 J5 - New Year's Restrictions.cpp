#include <bits/stdc++.h>
using namespace std;
const int MM = 200;
int N, M, r[MM][2], ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for (int i=0; i<M; i++) { cin >> r[i][0] >> r[i][1]; r[i][0]--; r[i][1]--; }
    for (int mask=0; mask<(1<<N); mask++) {
        for (int j=0; j<M; j++) {
            if ((mask&(1<<r[j][0])) && (mask&(1<<r[j][1]))) goto next;
        }
        ans = max(ans, __builtin_popcount(mask));
        next: ;
    }
    cout << ans << '\n';
}