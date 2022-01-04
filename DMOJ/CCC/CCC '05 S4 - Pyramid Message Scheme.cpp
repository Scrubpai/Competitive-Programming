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

int L, N; unordered_map<string, int> mp; vector<string> lis;

void solve() {

    cin >> L; string str;
    while (L--) {
        cin >> N;
        mp.clear(); lis.clear();
        for (int i = 0; i < N; i++) { cin >> str; lis.push_back(str); }
        string prev = ""; mp[lis[lis.size() - 1]] = 1; int maxd = 0;
        for (int i = 0; i < N; i++) {
            if (i == 0) { mp[lis[i]] = 2; prev = lis[i]; }
            else {
                if (mp[lis[i]] != 0) { prev = lis[i]; continue; }
                else { mp[lis[i]] = mp[prev] + 1; prev = lis[i]; }
            }
            maxd = max(maxd, mp[lis[i]]);
        }
        cout << (N - 2 * (maxd-1)) * 10 << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}