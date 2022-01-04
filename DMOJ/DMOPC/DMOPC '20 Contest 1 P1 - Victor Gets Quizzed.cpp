#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int n; string s;

void solve(int tc) {

    cin >> n;
    while (n--) {
        cin >> s;
        bool math = 0, cs = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'M') math = 1;
            if (s[i] == 'C') cs = 1;
        }
        if (math && cs) cout << "NEGATIVE MARKS" << nl;
        else if (math || cs) cout << "FAIL" << nl;
        else cout << "PASS" << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}