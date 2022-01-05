#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
#define nl '\n'
int N, Q, a[MM], pre[26][MM], suf[26][MM]; string s;
void solve(int tc) {
    cin >> N >> Q >> s;
    for (int i = 0; i < N; i++) a[i+1] = s[i] - 'A';
    for (int i = 0; i < 26; i++) {
        for (int l = 1, r = 1; l <= N; ) {
            pre[i][l] = pre[i][l-1];
            if (a[l] == i) {
                pre[i][l]++; r = l + 1;
                while (r <= N && a[r] >= i) pre[i][r] = pre[i][r-1], r++;
                l = r;
            } else l++;
        }
        for (int r = N, l = N; r >= 1; ) {
            suf[i][r] = suf[i][r+1];
            if (a[r] == i) {
                suf[i][r]++; l = r-1;
                while (l >= 1 && a[l] >= i) suf[i][l] = suf[i][l+1], l--;
                r = l;
            } else r--;
        }
    }
    for (int i = 1, l, r; i <= Q; i++) {
        cin >> l >> r;
        int ans = 0;
        for (int j = 0; j < 26; j++) {
            ans += pre[j][l-1] + suf[j][r+1];
        }
        cout << ans << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /* cin >> tc; */ for (int t = 1; t <= tc; t++) solve(t); return 0; }