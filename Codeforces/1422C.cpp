#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;
const int MM = 1e5 + 5;
const int MOD = 1e9 + 7;

string s; int d[MM]; ll suf[MM], p[MM], ans;

void solve(int tc) {

    cin >> s; int n = s.size(); p[0] = 1;
    for (int i = 0; i < n; i++) d[i+1] = s[i]-'0';
    for (int i = 1; i <= n; i++) {
        suf[i] = (suf[i-1] + i * p[i-1]) % MOD;
        p[i] = (p[i-1] * 10) % MOD;
    }
    for (int i = 1; i <= n; i++) {
        ll l = (1LL * i * (i - 1) / 2) % MOD, r = n - i;
        ans = (ans + 1LL * l * p[r] * d[i]) % MOD;
        ans = (ans + 1LL * suf[r] * d[i]) % MOD;
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}