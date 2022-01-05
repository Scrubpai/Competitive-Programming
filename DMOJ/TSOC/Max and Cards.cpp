#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
typedef pair<ll, pair<ll, ll> > pii;
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
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
#define f first
#define s second
#define nl '\n'
const int MN = 100005;
const int MV = 1000005;

ll N, Q; ll idx[22]; ll ans[22];

void findPermutation(ll q) {
    ll div = 1;
    for (ll i=0; i<N; i++) { ans[i] = i+1; idx[i] = 0; }
    for (ll i=1; i<=N; i++) {
        if ((q/div)==0) break;
        idx[N-i] = (q / div) % i;
        div*=i;
    }
    for (ll i=0; i<N; i++) {
        ll cur = idx[i] + i;
        if (cur!=i) {
            ll val = ans[cur];
            for (ll j=cur; j>i; j--) ans[j] = ans[j-1];
            ans[i] = val;
        }
    }
    for (ll i=0; i<N; i++) cout << ans[i] << " ";
    cout << nl;
}

void solve() {

    cin >> N >> Q;
    for (ll i=0, k; i<Q; i++) {
        cin >> k;
        findPermutation(k);
    }

}

int32_t main() {
   // ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}