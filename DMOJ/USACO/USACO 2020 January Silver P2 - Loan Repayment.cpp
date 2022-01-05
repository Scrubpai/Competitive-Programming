#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

ll N, K, M;

bool check(ll x) {
    ll days = 0, g = 0, tot = 0;
    while (days < K) {
        ll k = (N - g) / x;
        if (k <= M) break;
        ll t = min((N - g - k * x) / k + 1, K - days);
        days += t; tot += t * k; g += t * k;
        if (tot >= N) return 1;
    }
    if (days <= K) tot += (K - days) * M;
    return tot >= N;
}

void solve(int tc) {

    cin >> N >> K >> M;
    ll lo = 1, hi = N, ans = 0;
    check(5);
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) lo = mid + 1, ans = max(ans, mid);
        else hi = mid - 1;
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}