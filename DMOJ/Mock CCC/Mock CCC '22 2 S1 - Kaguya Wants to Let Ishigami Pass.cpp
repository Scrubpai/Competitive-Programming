#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+5;
int N, K, ans; string s[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K;
    for (int i=0; i<N; i++) cin >> s[i];
    for (int i=0; i<(1<<K); i++) {
        int low = 1e9;
        for (int j=0; j<N; j++) {
            int cnt = 0;
            for (int k=0; k<K; k++) {
                if (s[j][k] == 'T' && (i&(1<<k)) || (s[j][k] == 'F' && !(i&(1<<k)))) cnt++;
            }
            low = min(low, cnt);
        }
        ans = max(ans, low);
    }
    cout << ans << '\n';
}