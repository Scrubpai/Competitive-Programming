#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int n; string s; char grid[2005][2005];

void solve(int tc) {

    cin >> n >> s;
    for (int i = 0; i <= 2000; i++) {
        for (int j = 0; j <= 2000; j++) {
            grid[i][j] = '.';
        }
    }
    int r = 1000, c = 1000, mnr = 3000, mxr = 0, mnc = 3000, mxc = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '^') {
            grid[r][c] = '/';
            mnr = min(mnr, r); mxr = max(mxr, r); mnc = min(mnc, c); mxc = max(mxc, c);
            r--; c++;
        } else if (s[i] == 'v') {
            r++;
            char x = (char)92;
            grid[r][c] = x;
            mnr = min(mnr, r); mxr = max(mxr, r); mnc = min(mnc, c); mxc = max(mxc, c);
            c++;
        } else {
            grid[r][c] = '_';
            mnr = min(mnr, r); mxr = max(mxr, r); mnc = min(mnc, c); mxc = max(mxc, c);
            c++;
        }
    }
    for (int i = mnr; i <= mxr; i++) {
        for (int j = mnc; j <= mxc; j++) {

            cout << grid[i][j];
        }
        cout << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}