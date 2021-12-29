#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5, inf = 0x3F3F3F3F;
#define nl '\n'
int N, T = 10; string str; set<ll> dic; ll base = 131;
ll h(string s) {
    ll h = 0;
    for (int i=0; i<(int)s.size(); i++) h = h * base + s[i];
    return h;
}
void solve(int tc) {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> str;
        dic.insert(h(str));
    }
    while (T--) {
        cin >> str;
        int sz = (int)str.size();
        vector<int> dp(sz+1, inf); dp[0] = 0;
        vector<ll> hsh(sz+1), p(sz+1); p[0] = 1;
        for (int i=0; i<sz; i++) {
            hsh[i+1] = hsh[i] * base + str[i];
            p[i+1] = p[i] * base;
        }
        for (int i=1; i<=sz; i++) {
            for (int j=1; j<=i; j++) {
                ll sub = hsh[i] - hsh[j-1] * p[i-j+1];
                if (dic.count(sub)) dp[i] = min(dp[i], dp[j-1] + 1);
            }
        }
        cout << dp[sz]-1 << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(tc); return 0; }