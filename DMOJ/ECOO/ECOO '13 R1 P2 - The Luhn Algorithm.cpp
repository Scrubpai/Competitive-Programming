#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int get(int x) { int ret = 0; while (x) { ret += x%10; x/=10; } return ret; }
void solve(int tc) {
    for (int t=0; t<5; t++) {
        string s; cin >> s; int tot = 0;
        for (int i=0; i<(int)s.size(); i++) {
            if (i%2==0) tot += get(2*(s[s.size()-i-1]-'0'));
            else tot += s[s.size()-i-1]-'0';
        }
        cout << (10 - tot%10)%10;
    }
    cout << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 5; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(tc); return 0; }