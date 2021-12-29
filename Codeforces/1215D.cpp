#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
#define nl '\n'
int n, num[MM]; string s;
void solve(int tc) {
    cin >> n >> s;
    int lsum = 0, rsum = 0, qlft = 0, qrit = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i-1] == '?') {
            if (i <= n/2) qlft++;
            else qrit++;
        } else {
            if (i <= n/2) lsum += s[i-1] - '0';
            else rsum += s[i-1] - '0';
        }
    }
    if (lsum == rsum) {
        if (qlft == qrit) cout << "Bicarp" << nl;
        else cout << "Monocarp" << nl;
    } else if (lsum > rsum) {
        if (qlft >= qrit) cout << "Monocarp" << nl;
        else {
            qrit -= qlft;
            if (rsum + 9*(qrit/2) > lsum || rsum + 9*(qrit/2) < lsum) cout << "Monocarp" << nl;
            else cout << "Bicarp" << nl;
        }
    } else {
        //rsum > lsum
        if (qrit >= qlft) cout << "Monocarp" << nl;
        else {
            qlft -= qrit;
            if (lsum + 9*(qlft/2) > rsum || lsum + 9*(qlft/2) < rsum) cout << "Monocarp" << nl;
            else cout << "Bicarp" << nl;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}