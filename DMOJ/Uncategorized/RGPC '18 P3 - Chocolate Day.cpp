#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int N, T, L, psa[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> T;
    for (int i=0, a, b, c; i<T; i++) {
        cin >> a >> b >> c;
        psa[a] += c; psa[b+1] -= c;
    }
    for (int i=1; i<=N; i++) psa[i] += psa[i-1];
    cin >> L;
    int ans = 0;
    for (int i=1, l=0; i<=N; i++) {
        psa[i] += psa[i-1];
        while (l<i && psa[i] - psa[l] > L) l++;
        ans = max(ans, i-l);
    }
    printf("%d\n", ans);
    return 0;
}