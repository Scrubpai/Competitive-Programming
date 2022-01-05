#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5, mod = 998244353;
#define nl '\n'
int N, K, dp[MM][3]; ll ans; string str;
ll get(int a, int b) {
    //a choose b
    ll ret = 1;
    for (int i=0; i<b; i++) ret *= 1ll * (a - i);
    for (int i=1; i<=b; i++) ret /= 1ll * i;
    return ret%mod;
}
void solve(int tc) {
    cin >> N >> K >> str;
    string perm = "ACW";
    do {
        memset(dp, 0, sizeof(dp));
        if (str[0]==perm[0]) dp[0][0]=1;
        for (int i=1; i<N; i++) {
            if (str[i%N]==perm[0]) dp[i][0]++;
            else if (str[i%N]==perm[1]) dp[i][1]+=dp[i-1][0];
            else if (str[i%N]==perm[2]) dp[i][2]+=dp[i-1][1];
            dp[i][0]+=dp[i-1][0]; dp[i][1]+=dp[i-1][1]; dp[i][2]+=dp[i-1][2];
            dp[i][0]%=mod; dp[i][1]%=mod; dp[i][2]%=mod;
        }
        if (perm == "WAC") ans = (ans + 1ll*dp[N-1][2]*get(K+2, 3)) % mod;
        else if (perm == "CAW") ans = (ans + 1ll*dp[N-1][2]*get(K, 3)) % mod;
        else ans = (ans + 1ll*dp[N-1][2]*get(K+1, 3)) % mod;
    } while (next_permutation(perm.begin(), perm.end()));
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }