#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 3e4+5;
#define nl '\n'
int B, N, D, c[MM], v[MM], dp[3005][51]; multiset<pii, greater<pii>> st[51];
void solve(int tc) {
    cin >> B >> N >> D;
    for (int i = 1; i <= N; i++) {
        cin >> c[i] >> v[i];
        st[c[i]].insert({v[i], i});
    }
    for (int i = 1, a, b, x, y; i <= D; i++) {
        cin >> a >> b >> x >> y;
        auto itt = st[c[a]].lower_bound({v[a], a}); st[c[a]].erase(itt);
        c[a] = b;
        st[b].insert({v[a], a});
        for (int j = 1; j <= B; j++) {
            int cnt = 0;
            for (auto it = st[j].begin(); it != st[j].end(); it++) {
                if (it->second >= x && it->second <= y) {
                    int val = it->first;
                    for (int k = B; k >= j; k--) dp[i][k] = max(dp[i][k], dp[i][k-j] + val);
                    cnt++;
                }
                if (cnt * j > B) break;
            }
        }
        cout << dp[i][B] << nl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}