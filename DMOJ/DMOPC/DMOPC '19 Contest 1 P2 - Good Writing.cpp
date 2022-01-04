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
    while (exp > 0) {
        if (exp % 2 == 1) ret = (ret * b) % MOD;
        exp /= 2;
        b = (b * b) % MOD;
    }
    return ret;
}

int q, n, k; ll len[34];
string str1 = "Good writing is good writing is good writing.";
string str2 = "Good writing is good ";
string str3 = " writing is good ";
string str4 = " is good writing.";

char fun(int n, int k) {
    if (n == 0 && k < str1.size()) return str1[k];
    if (k < str2.size()) return str2[k];
    k -= str2.size();
    if (k < len[n - 1]) return fun(n - 1, k);
    k -= len[n - 1];
    if (k < str3.size()) return str3[k];
    k -= str3.size();
    if (k < len[n - 1]) return fun(n - 1, k);
    k -= len[n - 1];
    if (k < str4.size()) return str4[k];
    return '.';
}

void solve() {

    cin >> q; len[0] = str1.size();
    for (int i = 1; i <= 30; i++) len[i] = str2.size() + str3.size() + str4.size() + 2 * len[i - 1];
    while (q--) {
        cin >> n >> k; k--;
        cout << fun(n, k) << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}