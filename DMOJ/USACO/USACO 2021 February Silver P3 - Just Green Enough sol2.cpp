#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 505;
#define nl '\n'
int N, a[MM][MM], b[MM][MM];
ll fun(int x[][MM]) {
    ll ret = 0;
    for (int i=1; i<=N; i++) {
        vector<int> ones(N+5, 1);
        for (int j=i; j<=N; j++) {
            int run = 0;
            for (int k=1; k<=N; k++) {
                ones[k] = ones[k] & x[j][k];
                if (ones[k]) ret += ++run;
                else run = 0;
            }
        }
    }
    return ret;
}
void solve(int tc) {
    cin >> N;
    for (int i=1; i<=N; i++) {
        for (int j=1, g; j<=N; j++) {
            cin >> g;
            a[i][j] = g >= 100;
            b[i][j] = g > 100;
        }
    }
    cout << fun(a) - fun(b) << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }