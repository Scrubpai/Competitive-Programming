#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 505;
#define cl(a, b) memset(a, b, sizeof(a))
#define nl '\n'
#define f first
#define s second
int N, a[MM][MM], b[MM][MM], psa[MM][MM];
ll fun(int x[][MM]) {
    cl(psa, 0);
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            psa[i][j] = x[i][j] ? psa[i][j-1] + 1 : 0;
        }
    }
    ll ret = 0;
    for (int j=1; j<=N; j++) {
        ll sum = 0;
        stack<pii> stk;
        for (int i=1; i<=N; i++) {
            int h = 1;
            while (!stk.empty() && stk.top().f > psa[i][j]) {
                sum -= 1ll * stk.top().s * (stk.top().f - psa[i][j]);
                h += stk.top().s;
                stk.pop();
            }
            sum += psa[i][j];
            ret += sum;
            stk.push({psa[i][j], h});
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