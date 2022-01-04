#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
#define endl '\n'
#define INF 0x3f3f3f3f // for int
#define LL_INF 0x3f3f3f3f3f3f3f3f // for ll
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mpp make_pair
#define pb push_back
#define f first
#define s second
#define nl '\n'
const int MN = 1000000;

ll H, V; ll ans;

ll gcd(ll x, ll y) {
    if (x%y==0) return y;
    else return gcd(y, x%y);
}

void solve() {

    cin >> H >> V;
    ans = (H*(H-1)*V*(V-1))/4;

    for (ll r=1; r<H; r++) {
        for (ll c=1; c<V; c++) {
            ll x = gcd(r, c); ll tmpR = r + c/x; ll tmpC = c + r/x;
            while (tmpR<=H && tmpC<=V) {
                ans+= (V-tmpC)*(H-tmpR);
                tmpR += c/x; tmpC += r/x;
            }
        }
    }

    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}