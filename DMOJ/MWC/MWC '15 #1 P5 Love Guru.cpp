#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<string> vs;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, pii> pp;
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
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 10;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll pwmd(ll b, ll exp) {
    ll ret = 1;
    while (exp>0) {
        if (exp%2==1) ret = (ret*b)%MOD;
        exp/=2;
        b = (b*b)%MOD;
    }
    return ret;
}

string s1, s2; int v1, v2;

void solve() {

    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] >= 'a' && s1[i] <= 'z') v1 += pwmd(s1[i] - 'a' + 1, i + 1);
        else v1 += pwmd(s1[i] - 'A' + 1, i + 1);
    }
    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] >= 'a' && s2[i] <= 'z') v2 += pwmd(s2[i] - 'a' + 1, i + 1);
        else v2 += pwmd(s2[i] - 'A' + 1, i + 1);
    }
    v1 %= 10; v2 %= 10;
    if (v1 == 0) v1 = 10; if (v2 == 0) v2 = 10;
    cout << v1 + v2 << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}