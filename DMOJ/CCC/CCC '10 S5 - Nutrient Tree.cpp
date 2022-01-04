#include <bits/stdc++.h>
using namespace std;
#define lc (u<<1)
#define rc ((u<<1)|1)
string s; int pos, x, n[400], dp[400][2505], lft[2505], rit[2505];
void build(int u) {
    while ((pos < (int)s.size()) && (s[pos] == ')' || s[pos] == ' ')) pos++;
    if (pos >= (int)s.size()) return;
    if (s[pos] == '(') { pos++; build(lc), build(rc); }
    else {
        int t = 0;
        while ((pos < (int)s.size()) && (s[pos] >= '0' && s[pos] <= '9')) t = 10*t+(s[pos++]-'0');
        n[u] = t;
    }
}
void solve(int u) {
    if (n[u]) {
        for (int i=0; i<=x; i++) dp[u][i] = n[u] + i;
        return;
    }
    solve(lc); solve(rc);
    for (int i=0; i<=x; i++) {
        lft[i] = rit[i] = 0;
        for (int j=0; j<=i; j++) {
            lft[i] = max(lft[i], min((1+j)*(1+j), dp[lc][i-j]));
            rit[i] = max(rit[i], min((1+j)*(1+j), dp[rc][i-j]));
        }
    }
    for (int i=0; i<=x; i++) {
        for (int j=0; j<=i; j++) {
            dp[u][i] = max(dp[u][i], lft[j] + rit[i-j]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    getline(cin, s); cin >> x;
    build(1); solve(1); printf("%d\n", dp[1][x]);
}