#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 1e6+1;
int n, h[MM], j[MM], stk[MM], tt;

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) cin >> j[i];
    for (int i = n; i >= 1; i--) {
        while (tt && h[stk[tt]] <= h[i]) tt--;
        stk[++tt] = i;
        if (tt - j[i] <= 0) j[i] = -1;
        else j[i] = h[stk[tt-j[i]]];
    }
    for (int i = 1; i <= n; i++) cout << j[i] << ' ';

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}