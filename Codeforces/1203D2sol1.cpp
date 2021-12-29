#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
#define nl '\n'
string s, t; int pre[MM], suf[MM];
bool check(int removed) {
    for (int i = 1; i + removed - 1 < (int)s.size(); i++) {
        if (pre[i-1] + suf[i+removed] >= (int)t.size()) return 1;
    }
    return 0;
}
void solve(int tc) {
    cin >> s >> t; s = " " + s;
    int j = 0;
    for (int i = 1; i < s.size(); i++) {
        pre[i] = pre[i-1];
        if (j < t.size() && s[i] == t[j]) j++, pre[i]++;
    }
    j = (int)t.size() - 1;
    for (int i = (int)s.size() - 1; i >= 1; i--) {
        suf[i] = suf[i+1];
        if (j >= 0 && s[i] == t[j]) j--, suf[i]++;
    }
    int lo = 0, hi = (int)s.size() - (int)t.size() - 1, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) lo = mid + 1, ans = max(ans, mid);
        else hi = mid - 1;
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}