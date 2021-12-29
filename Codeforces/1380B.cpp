#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
#define nl '\n'
string s;
void solve(int tc) {
    cin >> s;
    int R = 0, S = 0, P = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') R++;
        else if (s[i] == 'S') S++;
        else P++;
    }
    int mx = max({R, S, P});
    if (mx == R) { for (int i = 0; i < s.size(); i++) cout << 'P'; }
    else if (mx == P) { for (int i = 0; i < s.size(); i++) cout << 'S'; }
    else { for (int i = 0; i < s.size(); i++) cout << 'R'; }
    cout << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}