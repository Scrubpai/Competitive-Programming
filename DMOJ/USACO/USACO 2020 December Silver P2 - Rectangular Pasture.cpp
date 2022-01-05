#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define nl '\n'
int N, psa[2505][2505]; pii pts[2505]; vector<int> x, y;
int query(int x1, int y1, int x2, int y2) { return psa[x2][y2] - psa[x1-1][y2] - psa[x2][y1-1] + psa[x1-1][y1-1]; }
void solve(int tc) {
    cin >> N; x.push_back(-1); y.push_back(-1);
    for (int i = 0, a, b; i < N; i++) {
        cin >> a >> b; pts[i] = {a, b};
        x.push_back(a); y.push_back(b);
    }
    sort(x.begin(), x.end()); sort(y.begin(), y.end());
    for (int i = 0; i < N; i++) {
        pts[i].first = lower_bound(x.begin(), x.end(), pts[i].first) - x.begin();
        pts[i].second = lower_bound(y.begin(), y.end(), pts[i].second) - y.begin();
        psa[pts[i].first][pts[i].second]++;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int x1 = pts[i].first, x2 = pts[j].first, y1 = pts[i].second, y2 = pts[j].second;
            int lft = query(1, min(y1, y2), min(x1, x2), max(y1, y2));
            int rit = query(max(x1, x2), min(y1, y2), N, max(y1, y2));
            ans += 1ll * lft * rit;
        }
    }
    cout << ans + 1 << nl;
}
int32_t main() {
    //freopen("", "r", stdin); freopen("", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}