#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 1e4;
int n, l, S, ans;

struct line {
    int x, v;
};
bool cmp(line a, line b) { return a.x < b.x; }

void solve(int tc) {

    cin >> n >> l >> S; vector<line> vec;
    for (int i = 0, a, b, s; i < n; i++) {
        cin >> a >> b >> s;
        vec.push_back({a, s}); vec.push_back({b + 1, -s});
    }
    vec.push_back({1, 0}); vec.push_back({l+1, 0});
    int cur = 0, pre = 1;
    sort(vec.begin(), vec.end(), cmp);
    for (line x : vec) {
        if (cur < S) ans += (x.x - pre);
        cur += x.v; pre = x.x;
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