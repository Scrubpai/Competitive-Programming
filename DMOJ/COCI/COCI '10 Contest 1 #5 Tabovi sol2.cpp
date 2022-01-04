#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N, P[1005], K[1005], diff[1005], ans;
void fun(int l, int r) {
    int prev = 0;
    for (int k = 1; k <= 80; k++) {
        bool flag = 0; int num = 0;
        for (int i = l; i <= r; i++) {
            if (diff[i] == k) { flag = 1; break; }
        }
        if (!flag) continue;
        for (int i = l; i <= r; i++) {
            if (diff[i] >= k && diff[i-1] < k) num++;
        }
        ans += num * (k - prev);
        prev = k;
    }
    for (int i = l; i <= r; i++) diff[i] = 0;
}
void solve(int tc) {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> P[i];
    for (int i = 1; i <= N; i++) { cin >> K[i]; diff[i] = abs(P[i] - K[i]); }
    for (int l = 0, r = 0; l <= N; ) {
        while (r <= N && (P[l] < K[l] == P[r] < K[r])) r++;
        fun(l, r-1); l = r;
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