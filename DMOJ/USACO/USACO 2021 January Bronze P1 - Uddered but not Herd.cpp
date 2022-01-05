#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
string cow, str; unordered_map<char, int> mp;
void solve(int tc) {
    cin >> cow >> str;
    for (int i=0; i<26; i++) mp[cow[i]] = i;
    int ans = 1, cur = -1;
    for (int i=0; i<(int)str.size(); i++) {
        if (mp[str[i]] <= cur) ans++;
        cur = mp[str[i]];
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }