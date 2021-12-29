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
typedef double ld;
typedef long double lld;
#define INF 0x3f3f3f3f // for int
#define LL_INF 0x3f3f3f3f3f3f3f3f // for ll
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define mpp make_pair
#define pb push_back
#define AUT auto
//coordinate compression:sort(val.begin(), val.end());
//		val.resize(unique(val.begin(), val.end()) - val.begin());
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 1e9 + 7;
const lld pi = 3.14159265358979323846;

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

const int MM = 2e5 + 5;
int n, tp, d, num; ll sum;
set<int> use, rem, fire;

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tp >> d; sum += d;
        if (d > 0) {
            if (tp) num++;
            else fire.insert(d);
            if (rem.size() && d <= *rem.rbegin()) rem.insert(d);
            else { use.insert(d); sum += d; }
        } else {
            if (tp) num--;
            else fire.erase(-d);
            if (rem.size() && -d <= *rem.rbegin()) rem.erase(-d);
            else { use.erase(-d); sum += d; }
        }
        while (use.size() > num) {
            int x = *use.begin();
            rem.insert(x);
            use.erase(x);
            sum -= x;
        }
        while (use.size() < num) {
            int x = *rem.rbegin();
            rem.erase(x);
            use.insert(x);
            sum += x;
        }
        ll add = 0;
        if (use.size()) {
            if (fire.size()) {
                add = *fire.rbegin();
            }
            add -= *use.begin();
        }
        add = min(add, 0LL);
        cout << sum + add << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1;
   // cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);
    return 0;
}