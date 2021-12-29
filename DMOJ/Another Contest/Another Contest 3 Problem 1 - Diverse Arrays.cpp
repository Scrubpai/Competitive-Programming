#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+5;
int N, K, a[MM], f[MM], cnt; ll ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K;
    for (int l=1, r=1; r<=N; r++) {
        cin >> a[r];
        if (++f[a[r]] == 1) cnt++;
        while (cnt >= K) {
            ans += N-r+1;
            if (--f[a[l++]] == 0) cnt--;
        }
    }
    printf("%lld\n", ans);
    return 0;
}