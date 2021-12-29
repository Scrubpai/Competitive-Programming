#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define nl '\n'

const int MM = 2e5 + 5;
int n; ll a[MM], dp[MM]; unordered_map<ll, int> mp; vector<pii> val;

void solve(int tc) {

    cin >> n; val.push_back({0, 0});
    ll sum = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; sum += a[i];
        if (mp[sum] == 0 && sum != 0) { mp[sum] = i; continue; }
        if (mp[sum] == 0 && sum == 0) val.push_back({1, i});
        else if (mp[sum] != 0) val.push_back({mp[sum]+1, i});
        mp[sum] = i;
    }
    if (val.size() == 1) { cout << 0 << nl; return; }
    sort(val.begin(), val.end());
    for (int i = 1; i < val.size(); i++) dp[i] = 1;
    for (int i = 1; i < val.size(); i++) {
        dp[i] = max(dp[i], dp[i-1]);
        int nxt = lower_bound(val.begin(), val.end(), make_pair(val[i].second, 0)) - val.begin();
        if (nxt != val.size()) dp[nxt] = max(dp[nxt], dp[i] + 1);
        ans = max(ans, dp[i]);
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1;// cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}