#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
char a[3][3];
void solve(int tc) {
    int cnt = 0;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'o') cnt++;
        }
    }
    if (cnt == 1) {
        if (a[1][1] == 'o') cout << 1 << nl;
        else cout << "unknown" << nl;
    } else if (cnt == 2) {
        if ((a[0][0] == 'o' && a[2][2] == 'o') || (a[0][2] == 'o' && a[2][0] == 'o')) cout << 2 << nl;
        else cout << "unknown" << nl;
    } else if (cnt == 3) {
        if ((a[0][0] == 'o' && a[1][1] == 'o' && a[2][2] == 'o') || (a[0][2] == 'o' && a[1][1] == 'o' && a[2][0] == 'o')) cout << 3 << nl;
        else cout << "unknown" << nl;
    } else if (cnt == 4) {
        if (a[0][0] == 'o' && a[0][2] == 'o' && a[2][0] == 'o' && a[2][2] == 'o') cout << 4 << nl;
        else cout << "unknown" << nl;
    } else if (cnt == 5) {
        if (a[0][0] == 'o' && a[0][2] == 'o' && a[1][1] == 'o' && a[2][0] == 'o' && a[2][2] == 'o') cout << 5 << nl;
        else cout << "unknown" << nl;
    } else if (cnt == 6) {
        if ((a[1][0] != 'o' && a[1][1] != 'o' && a[1][2] != 'o') || (a[0][1] != 'o' && a[1][1] != 'o' && a[2][1] != 'o')) cout << 6 << nl;
        else cout << "unknown" << nl;
    } else {
        cout << "unknown" << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }