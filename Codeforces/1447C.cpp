#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pi;
#define nl '\n'

const int MM = 2e5 + 5;
int n; ll W; pi w[MM];

void solve(int tc) {

    cin >> n >> W; vector<int> ans;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x; w[i] = {x, i};
    }
    sort(w + 1, w + 1 + n);
    ll tot = 0;
    for (int i = n; i >= 1; i--) {
        if (tot + w[i].first <= W) tot += w[i].first, ans.push_back(w[i].second);
    }
    if (tot >= (W+1ll)/2) {
        cout << ans.size() << nl;
        for (int x : ans) cout << x << ' ';
        cout << nl;
    } else {
        cout << -1 << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}