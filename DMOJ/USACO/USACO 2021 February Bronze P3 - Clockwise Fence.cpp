#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
void solve(int tc) {
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        int x = 0;
        for (int i=0; i<(int)s.size()-1; i++) {
            if (s[i] == s[i+1]) continue;
            if ((s[i] == 'N' && s[i+1] == 'E') || (s[i] == 'E' && s[i+1] == 'S') || (s[i] == 'S' && s[i+1] == 'W') || (s[i] == 'W' && s[i+1] == 'N')) x++;
            else x--;
        }
        if (x>0) cout << "CW" << nl;
        else cout << "CCW" << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }