#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll P, Y, T;
bool chk(ll N) {
    ll tot = 0;
    for (int i=1; i<=Y; i++) {
        tot += N;
        tot += tot*P/100;
        if (tot >= T) return 1;
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> P >> Y >> T;
    ll lo = 1, hi = 1e16;
    while (lo < hi) {
        ll mid = (lo+hi)/2;
        if (chk(mid)) hi = mid;
        else lo = mid+1;
    }
    printf("%lld\n", hi);
}