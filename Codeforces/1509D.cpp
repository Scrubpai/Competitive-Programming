#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n, cnt[3][2]; string s[3];
void solve(int tc) {
    cin >> n >> s[0] >> s[1] >> s[2];
    for (int i=0; i<3; i++) {
        cnt[i][0] = cnt[i][1] = 0;
        for (int j=0; j<2*n; j++) cnt[i][s[i][j]-'0']++;
        for (int j=i-1; j>=0; j--) {
            for (char c='0'; c<='1'; c++) {
                int m = c-'0';
                if (cnt[i][m] <= n && cnt[j][m] <= n) {
                    for (int k1 = 0, k2 = 0; k1 < 2*n || k2 < 2*n;) {
                        if (k1 == 2*n) { cout << s[j][k2]; k2++; }
                        else if (k2 == 2*n) { cout << s[i][k1]; k1++; }
                        else if (s[i][k1] != c && s[j][k2] != c) { cout << s[i][k1]; k1++; k2++; }
                        else {
                            if (s[i][k1] == c) { cout << s[i][k1]; k1++; }
                            else { cout << s[j][k2]; k2++; }
                        }
                    }
                    cout << nl;
                    return;
                }
            }
        }
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }