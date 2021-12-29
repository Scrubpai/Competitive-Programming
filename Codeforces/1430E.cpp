#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MM = 2e5 + 5;
int n, bit[MM], ord[MM]; string s, rev; vector<int> pos[26]; ll ans;

int query(int p) {
    int ret = 0;
    for (; p >= 1; p -= p&-p) ret += bit[p];
    return ret;
}

void update(int p) {
    for (; p <= n; p += p&-p) bit[p]++;
}

void solve(int tc) {

    cin >> n >> s; rev = s; reverse(rev.begin(), rev.end()); s = " " + s; rev = " " + rev;
    for (int i = 1; i <= n; i++) {
        pos[s[i]-'a'].push_back(i);
    }
    for (int i = n; i >= 1; i--) {
        ord[i] = pos[rev[i]-'a'].back(); pos[rev[i]-'a'].pop_back();
        ans += query(ord[i]);
        update(ord[i]);
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