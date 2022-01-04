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
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
//#define f first
//#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 1000000000;

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

int n, r, freq[1001];

void solve() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> r; freq[r]++;
    }
    int f1 = -1, f2 = -1, v1 = -1, v2 = -1;
    for (int i = 1; i <= 1000; i++) {
        if (freq[i] > v1 || (freq[i] == v1 && f2 == freq[i])) { v2 = v1; f2 = f1; v1 = freq[i]; f1 = i; }
        else {
            if (freq[i] > v2) { v2 = freq[i]; f2 = i; }
            else if (freq[i] == v2 && abs(i - f1) > abs(f1 - f2)) { f2 = i; }
        }
    }
    cout << abs(f1 - f2) << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}