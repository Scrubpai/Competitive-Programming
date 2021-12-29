#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
//typedef pair<ll, pair<ll, ll> > pii;
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
const int MN = 1000001;
const int MOD = (int)1e9 + 7;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}

ll t, n, k;

void solve() {

    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n >> k;
        if (n%2!=k%2 || ((1+(2*k - 1))*k)/2>n) { cout << "NO" << nl; }
        else {
            ll k2 = k-1;
            ll x = ((1+(2*k2 - 1))*k2)/2;
            if ((n-x)%2==0) { cout << "NO" << nl; continue; }
            if ((n-x)<=(2*k2-1)) { cout << "NO" << nl; continue; }
            else cout << "YES" << nl;
        }
    }

}

int32_t main() {
   // ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}

