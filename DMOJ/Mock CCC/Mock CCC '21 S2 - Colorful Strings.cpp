#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
#define nl '\n'
string s; int cnt[26];
void solve(int tc) {
    cin >> s;
    ll ans = 0;
    for (int i=0; i<(int)s.size(); i++) {
        ll val = 1;
        for (int j=0; j<26; j++) {
            if (s[i]-'a'==j) continue;
            val = (val * (cnt[j]+1)) %mod;
        }
        ans = (ans + val) % mod;
        cnt[s[i]-'a']++;
    }
    cout << ans+1 << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }