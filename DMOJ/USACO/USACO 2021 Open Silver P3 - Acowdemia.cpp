#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, K, L, c[MM];
bool chk(int h) {
    if (h-c[h] > K) return 0;
    long long tot = 1ll*K*L;
    for (int i=1; i<=h; i++) {
        tot -= max(h-c[i], 0);
    }
    return tot>=0;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K >> L;
    for (int i=1; i<=N; i++) cin >> c[i];
    sort(c+1, c+1+N, greater<>());
    int lo = 0, hi = N;
    while (lo < hi) {
        int mid = (lo+1+hi)/2;
        if (chk(mid)) lo = mid;
        else hi = mid-1;
    }
    cout << lo << '\n';
}