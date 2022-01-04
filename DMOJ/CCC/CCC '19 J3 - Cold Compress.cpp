#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n; string str;
void solve(int tc) {
    cin >> n;
    for (int k=0; k<n; k++) {
        cin >> str;
        for (int i=0, j=0; i<str.size(); ) {
            while (j<str.size() && str[i] == str[j]) j++;
            cout << (j-i) << " " << str[i] << " ";
            i = j;
        }
        cout << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }