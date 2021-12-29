#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))

const int MM = 1e5 + 5;
string y; int dp[MM], pre[MM], a[MM];

void solve (int tc) {

    cin >> y; int n = y.size(); y = " " + y; ms(dp, -1); dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x = a[i] = y[i]-'0';
        int sq = (int)sqrt(x), cu = ceil(pow(x, 1.0/3.0));
        if (sq * sq == x && sq < 10 && dp[i-1] != -1) dp[i] = sq, pre[i] = i-1;
        else if (cu * cu * cu == x && cu < 10 && dp[i-1] != -1) dp[i] = cu, pre[i] = i-1;
        else {
            if (i >= 2) {
                x = 10*a[i-1] + a[i]; sq = (int)sqrt(x), cu = ceil(pow(x, 1.0/3.0));
                if (sq * sq == x && sq < 10 && dp[i-2] != -1) dp[i] = sq, pre[i] = i-2;
                else if (cu * cu * cu == x && cu < 10 && dp[i-2] != -1) dp[i] = cu, pre[i] = i-2;
                else {
                    if (i >= 3) {
                        x = 100*a[i-2] + 10*a[i-1] + a[i]; sq = (int)sqrt(x); cu = ceil(pow(x, 1.0/3.0));
                        if (sq * sq == x && sq < 10 && dp[i-3] != -1) dp[i] = sq, pre[i] = i-3;
                        else if (cu * cu * cu == x && cu < 10 && dp[i-3] != -1) dp[i] = cu, pre[i] = i-3;
                    }
                }
            }
        }
    }
    if (dp[n] == -1) cout << -1 << nl;
    else {
        int i = n; string ans;
        while (i != 0) {
            ans += to_string(dp[i]);
            i = pre[i];
        }
        reverse(ans.begin(), ans.end());
        cout << ans << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}