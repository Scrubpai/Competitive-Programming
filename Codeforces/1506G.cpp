#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
string s;
bool can(char c, const string &pre, set<char> &st) {
    int i=0;
    for (int j=0; i<s.size() && j<pre.size(); i++) {
        if (s[i] == pre[j]) j++;
    }
    for (; i<s.size(); i++) {
        if (s[i] == c) break;
    }
    i++;
    set<char> rem;
    for (; i<s.size(); i++) rem.insert(s[i]);
    for (char x : st) {
        if (x == c) continue;
        if (!rem.count(x)) return 0;
    }
    return 1;
}
void solve(int tc) {
    cin >> s;
    set<char> unused(s.begin(), s.end());
    string ans;
    while (!unused.empty()) {
        char c = 'a';
        for (char x : unused) {
            if (can(x, ans, unused)) c = max(c, x);
        }
        unused.erase(c);
        ans.push_back(c);
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }