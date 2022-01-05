#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5 + 5;
#define nl '\n'
int N, ans, cnt[MM];
void solve(int tc) {
    cin >> N;
    for (int i = 1, a, b; i < N; i++) { cin >> a >> b; cnt[a]++; cnt[b]++; }
    for (int i = 1; i <= N; i++) {
        int t = 1;
        while (t < cnt[i] + (i == 1)) { t *= 2; ans++; }
    }
    cout << ans + N - 1 << nl;
}
int32_t main() {
    //freopen("", "r", stdin); freopen("", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}