#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
const int MM = 1.5e5+5, LOG = 17;
int N, M, x[MM], y[MM], z[MM], dif[MM][17], ans[MM], st[LOG+5][MM];
int query(int l, int r) {
    int k = log2(r-l+1);
    return __gcd(st[k][l], st[k][r-(1<<k)+1]);
}
void solve(int tc) {
    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        cin >> x[i] >> y[i] >> z[i];
        dif[x[i]][z[i]]++; dif[y[i]+1][z[i]]--;
    }
    for (int i=1; i<=N; i++) {
        int lcm = 1;
        for (int j=1; j<=16; j++) {
            dif[i][j] += dif[i-1][j];
            if (dif[i][j]) lcm = lcm * j / __gcd(lcm, j);
        }
        ans[i] = st[0][i] = lcm;
    }
    for (int j=1; j<=LOG; j++) {
        for (int i=1; i+(1<<j)-1<=N; i++) {
            st[j][i] = __gcd(st[j-1][i], st[j-1][i+(1<<(j-1))]);
        }
    }
    for (int i=1; i<=M; i++) {
        if (query(x[i], y[i]) != z[i]) {
            cout << "Impossible" << nl;
            return;
        }
    }
    for (int i=1; i<=N; i++) cout << ans[i] << ' ';
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }