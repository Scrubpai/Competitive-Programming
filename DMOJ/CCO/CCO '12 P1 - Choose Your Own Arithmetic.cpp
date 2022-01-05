#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 5e6 + 5;
int W, D, V, x; vector<int> digits; bool ans[MM], dp[MM][7];

void rec(int cur, int moves) {
    if (dp[cur][moves]) return;
    if (moves == W) {
        ans[cur] = 1;
        return;
    }
    for (int dig : digits) {
        rec(cur * dig, moves + 1);
        rec(cur + dig, moves + 1);
    }
    dp[cur][moves] = 1;
}

void solve(int tc) {

    cin >> W >> D;
    for (int i = 1; i <= D; i++) {
        cin >> x;
        digits.push_back(x);
    }
    for (int dig : digits) rec(dig, 0);
    cin >> V;
    for (int i = 1; i <= V; i++) {
        cin >> x;
        if (ans[x]) cout << "Y" << nl;
        else cout << "N" << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}