#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
const int MOD = 1e9 + 7;
typedef long long ll;

const int MM = 2e5 + 5;
int n, psa1[MM], psa2[MM], psa3[MM]; ll dp[MM], k, ans; string s;
/*
 * psa1 for A
 * psa2 for C
 * psa3 for ?
 */

ll pwmd(ll b, ll exp) {
    ll ret = 1;
    while (exp > 0) {
        if (exp % 2 == 1) ret = (ret * b) % MOD;
        exp /= 2;
        b = (b * b) % MOD;
    }
    return ret;
}

void solve(int tc) {

    cin >> n >> s; s = " " + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'a') psa1[i] = 1;
        else if (s[i] == 'c') psa2[i] = 1;
        else if (s[i] == '?') psa3[i] = 1, k++;
        psa1[i] += psa1[i-1]; psa2[i] += psa2[i-1]; psa3[i] += psa3[i-1];
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] != 'b' && s[i] != '?') continue;
        ll exp = k;
        if (s[i] == '?') exp--;
        //choose A on left, C on right
        ans = (ans + 1LL * psa1[i-1] * (psa2[n] - psa2[i]) * pwmd(3, exp)) % MOD;
        //choose ? on the left, C on the right
        if (exp >= 1) ans = (ans + 1LL * psa3[i-1] * pwmd(3, exp - 1) * (psa2[n] - psa2[i])) % MOD;
        //choose A on the left, ? on the right
        if (exp >= 1) ans = (ans + 1LL * psa1[i-1] * pwmd(3, exp - 1) * (psa3[n] - psa3[i])) % MOD;
        //choose ? on both sides
        if (exp >= 2) ans = (ans + 1LL * psa3[i-1] * (psa3[n] - psa3[i]) * pwmd(3, exp - 2)) % MOD;
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1;// cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}