#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5, mod = 1e9+7;
#define nl '\n'
string N; int K, a[MM]; ll dp[MM][19]; unordered_set<int> st;
void solve(int tc) {
    cin >> N >> K;
    int n = N.size();
    for (int i=0; i<n; i++) {
        if (N[i] >= '0' && N[i] <= '9') a[i] = N[i]-'0';
        else a[i]=N[i]-'A'+10;
    }
    st.insert(a[0]);
    dp[0][1] = max(a[0]-1, 0);
    for (int i=0; i<n-1; i++) {
        dp[i+1][1] = 15;
        for (int j=0; j<a[i+1]; j++) {
            dp[i+1][(int)st.size() + ((int)(st.count(j))?0:1)]++;
        }
        for (int j=1; j<=K; j++) {
            dp[i+1][j] = (dp[i+1][j] + dp[i][j] * j) % mod;
            dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j] * (16-j)) % mod;
        }
        st.insert(a[i+1]);
    }
    cout << dp[n-1][K] + ((int)st.size()==K) ? 1 : 0 << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }