#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int N, K, sum, a[MM], id[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K; memset(id, -1, sizeof(id)); id[0] = 0;
    int ans = -1;
    for (int i=1; i<=N; i++) {
        cin >> a[i];
        sum = (sum + a[i]) % K;
        if (id[sum] == -1) id[sum] = i;
        else ans = max(ans, i-id[sum]);
    }
    printf("%d\n", ans);
}