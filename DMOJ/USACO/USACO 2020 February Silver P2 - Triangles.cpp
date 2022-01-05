#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))

const int MM = 1e5 + 5, mod = 1e9 + 7, shift = 1e4;
int n; pii p[MM]; ll ans, cx[2*shift+5], cy[2*shift+5], psax[2*shift+5], psay[2*shift+5], lastx[2*shift+5], lasty[2*shift+5];

void rotate() {
    for (int i = 0; i < n; i++) {
        int x = p[i].first, y = p[i].second;
        p[i] = {y, -x};
    }
    sort(p, p + n);
}

void calc() {
    ms(cx, 0); ms(cy, 0); ms(psax, 0); ms(psay, 0); ms(lastx, 0); ms(lasty, 0);
    for (int i = 0; i < n; i++) {
        int x = p[i].first + shift, y = p[i].second + shift;
        psax[x] = (psax[x] + (1ll * y - lastx[x]) * cx[x]) % mod;
        psay[y] = (psay[y] + (1ll * x - lasty[y]) * cy[y]) % mod;
        ans = (ans + psax[x] * psay[y]) % mod;
        lastx[x] = y; lasty[y] = x; cx[x]++; cy[y]++;
    }
}

void solve(int tc) {

    cin >> n;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        p[i] = {x, y};
    }
    sort(p, p + n);
    calc();
    rotate();
    calc();
    rotate();
    calc();
    rotate();
    calc();
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}