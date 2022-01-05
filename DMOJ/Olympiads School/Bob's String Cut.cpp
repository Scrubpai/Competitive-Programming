#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
#define nl '\n'
int N, pre[MM][26], suf[MM][26]; string s;
void solve(int tc) {
    cin >> N >> s; s = " " + s;
    for (int i = 1; i <= N; i++) {
        pre[i][s[i]-'a']++;
        for (int j = 0; j < 26; j++) pre[i][j] += pre[i-1][j];
    }
    for (int i = N; i >= 1; i--) {
        suf[i][s[i]-'a']++;
        for (int j = 0; j < 26; j++) suf[i][j] += suf[i+1][j];
    }
    int ans = 0;
    for (int i = 1; i < N; i++) {
        int distinct = 0;
        for (int j = 0; j < 26; j++) {
            if (pre[i][j] && suf[i+1][j]) distinct++;
        }
        ans = max(ans, distinct);
    }
    cout << ans << nl;
}
int32_t main() {
    //freopen("", "r", stdin); freopen("", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}