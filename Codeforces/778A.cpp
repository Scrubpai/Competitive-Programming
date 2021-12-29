#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 2e5 + 5;
#define nl '\n'
string p, t; pi a[MM];
bool check(int num) {
    int l = 0;
    for (int i = 1; i < t.size(); i++) {
        if (a[i].second > num) {
            if (t[i] == p[l]) l++;
        }
        if (l >= p.size()) return 1;
    }
    return 0;
}
void solve(int tc) {
    cin >> t >> p; t = " " + t;
    for (int i = 1, v; i < t.size(); i++) {
        cin >> v;
        a[i] = {v, i};
    }
    sort(a + 1, a + t.size());
    int lo = 0, hi = (int)t.size()-1, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) lo = mid + 1, ans = max(ans, mid);
        else hi = mid - 1;
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1;// cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}