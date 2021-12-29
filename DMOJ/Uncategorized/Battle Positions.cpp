#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int I, N, J, psa[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    scanf("%d %d %d", &I, &N, &J);
    for (int i=0, xi, xf, k; i<J; i++) {
        scanf("%d %d %d", &xi, &xf, &k);
        psa[xi] += k; psa[xf+1] -= k;
    }
    int ans = 0;
    for (int i=1; i<=I; i++) {
        psa[i] += psa[i-1];
        if (psa[i] < N) ans++;
    }
    printf("%d", ans);
    return 0;
}