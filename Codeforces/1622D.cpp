#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, k, c[5005][5005], psa[5005], ans; string s;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k >> s; s=" "+s;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=i; j++) {
            if (j==0 || j==i) c[i][j] = 1;
            else c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
        }
    }
    for (int i=1; i<=n; i++) psa[i] = psa[i-1] + (s[i] == '1');
    if (psa[n] < k) { cout << 1 << '\n'; return 0; }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            int cnta = psa[j] - psa[i-1], cntb = (j-i+1)-cnta;
            if (cnta > k) continue;
            if (s[i]=='0') cnta--;
            else cntb--;
            if (s[j]=='0') cnta--;
            else cntb--;
            if (cnta < 0 || cntb < 0) continue;
            ans = (ans + c[cnta+cntb][cnta]) % mod;
        }
    }
    cout << (ans+1)%mod << '\n';
}