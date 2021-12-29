#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5 + 5;
#define nl '\n'
int N, K, A[MM];
bool check(int len) {
    ll cuts = 0;
    for (int i = 1; i <= N; i++) {
        cuts += ((A[i] + len - 1) / len) - 1;
        if (cuts > K) return 0;
    }
    return 1;
}
void solve(int tc) {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    int lo = 1, hi = 1e9, ans = 1e9;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) ans = min(ans, mid), hi = mid - 1;
        else lo = mid + 1;
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}