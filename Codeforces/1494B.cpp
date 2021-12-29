#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N, cnt[4], tmp[4];
void solve(int tc) {
    cin >> N >> cnt[0] >> cnt[1] >> cnt[2] >> cnt[3];
    for (int i=0; i<16; i++) {
        tmp[0] = cnt[0]; tmp[1] = cnt[1]; tmp[2] = cnt[2]; tmp[3] = cnt[3];
        bool flag = 1;
        for (int j=0; j<4; j++) {
            if (i&(1<<j)) {
                tmp[j]--; tmp[(j-1+4)%4]--;
            }
        }
        for (int j=0; j<4; j++) {
            if (tmp[j]<0) { flag = 0; break; }
            else if (tmp[j]) {
                if (N-2 < tmp[j]) { flag = 0; break; }
            }
        }
        if (flag) { cout << "YES" << nl; return; }
    }
    cout << "NO" << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }