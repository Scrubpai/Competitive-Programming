#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5, MX=1e6+5;
int N, K, cnt, F[MM], freq[MX]; ll ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K;
    for (int r=1, l=1; r<=N; r++) {
        cin >> F[r];
        freq[F[r]]++;
        if (freq[F[r]] == 1) cnt++;
        while (cnt >= K) {
            ans += N-r+1;
            freq[F[l]]--;
            if (!freq[F[l++]]) cnt--;
        }
    }
    cout << ans << '\n';
    return 0;
}