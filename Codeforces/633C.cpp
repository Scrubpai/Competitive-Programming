#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4 + 5, MX = 1e5 + 5;
typedef long long ll;
#define INF 0x3f3f3f3f
#define nl '\n'
int n, m, dp[MM], pre[MM]; unordered_set<ll> st; string s, dict[MX]; ll hsh[MM], p[MM], base = 131; map<ll, int> mp;
ll get(int l, int r) {
    return hsh[r] - hsh[l-1] * p[r-l+1];
}
void solve(int tc) {
    cin >> n >> s;
    p[0] = 1;
    for (int i = 0; i < n; i++) {
        hsh[i+1] = hsh[i] * base + s[i];
        p[i+1] = p[i] * base;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s;
        dict[i] = s;
        reverse(s.begin(), s.end());
        ll h = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            h = h * base + tolower(s[j]);
        }
        st.insert(h);
        mp[h] = i;
    }
    memset(dp, -INF, sizeof(dp)); dp[0] = 0;
    vector<int> idx; idx.push_back(0);
    for (int r = 1; r <= n; r++) {
        for (int l : idx) {
            ll val = get(l+1, r);
            if (dp[l] + 1 > dp[r] && st.count(val)) {
                dp[r] = dp[l] + 1;
                pre[r] = l;
            }
        }
        if (dp[r] != -INF) idx.push_back(r);
    }
    vector<string> res;
    for (int i = n; i != 0; i = pre[i]) {
        res.push_back(dict[mp[get(pre[i]+1, i)]]);
    }
    reverse(res.begin(), res.end());
    cout << res[0];
    for (int i = 1; i < (int)res.size(); i++) cout << ' ' << res[i];
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}