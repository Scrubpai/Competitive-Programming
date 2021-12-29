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

const int MM = 1e5;
int n, freq[MM + 5], q, x; set<int> sq, rect, both; char ch;

void solve() {

    cin >> n; int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> x; freq[x]++; mx = max(mx, x);
    }
    for (int i = 1; i <= MM; i++) {
        if (freq[i] >= 8) both.insert(i);
        else if (freq[i] >= 6) sq.insert(i), rect.insert(i);
        else if (freq[i] >= 4) sq.insert(i);
        else if (freq[i] >= 2) rect.insert(i);
    }
    cin >> q;
    while (q--) {
        cin >> ch >> x;
        if (ch == '+') {
            freq[x]++;
        } else {
            freq[x]--;
        }
        if (freq[x] >= 8) { both.insert(x); sq.erase(x); rect.erase(x); }
        else if (freq[x] >= 6) { rect.insert(x); sq.insert(x); both.erase(x); }
        else if (freq[x] >= 4) { sq.insert(x); both.erase(x); rect.erase(x); }
        else if (freq[x] >= 2) { rect.insert(x); sq.erase(x); both.erase(x); }
        else { both.erase(x); sq.erase(x); rect.erase(x); }
        if (both.size() >= 1 || (sq.size() >= 1 && rect.size() >= 2) || (sq.size() >= 2)) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}