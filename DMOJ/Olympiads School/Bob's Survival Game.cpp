#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
#define nl '\n'
int N, T, M, cnt[MM];
void solve(int tc) {
    cin >> N >> T >> M;
    for (int i = 1, a; i <= M; i++) {
        cin >> a;
        cnt[a]++;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (T - (M - cnt[i]) > 0) ans++;
    }
    cout << ans << nl;
}
int32_t main() {
    //freopen("", "r", stdin); freopen("", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}