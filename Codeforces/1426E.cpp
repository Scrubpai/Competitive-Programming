#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define INF 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, a[4], b[4], tmpa[4], tmpb[4];

void solve(int tc) {

    cin >> n;
    int ans = INF; vector<pii> ord;
    for (int i = 1; i <= 3; i++) { cin >> a[i]; tmpa[i] = a[i]; }
    for (int i = 1; i <= 3; i++) { cin >> b[i]; tmpb[i] = b[i]; }
    ord.push_back({1, 1}); ord.push_back({1, 2}); ord.push_back({2, 2}); ord.push_back({2, 3}); ord.push_back({3, 1}); ord.push_back({3, 3});
    do {
        for (int i = 1; i <= 3; i++) tmpa[i] = a[i], tmpb[i] = b[i];
        for (int i = 0; i < 6; i++) {
            int x = ord[i].first, y = ord[i].second, v = min(tmpb[x], tmpa[y]);
            tmpb[x] -= v; tmpa[y] -= v;
        }
        int sum = 0;
        for (int i = 1; i <= 3; i++) {
            sum += tmpa[i];
        }
        ans = min(ans, sum);
    } while (next_permutation(ord.begin(), ord.end()));
    cout << ans << " ";
    ans = 0; ans += min(a[1], b[2]); ans += min(a[2], b[3]); ans += min(a[3], b[1]);
    cout << ans;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1;// cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}