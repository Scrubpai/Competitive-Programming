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

const int MM = 2e5 + 5;
int T, n, ans[MM]; string str; vector<int> zero, one; vector<int> tmp;

void solve() {

    cin >> T;
    while (T--) {
        cin >> n >> str; int cnt = 0; zero.clear(); one.clear();
        for (int i = 0; i < n; i++) {
            if (str[i] == '0') zero.push_back(i);
            else one.push_back(i);
            ans[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] == 0) {
                ans[i] = ++cnt; int idx = i, next_idx = -1;
                while (1) {
                    if (str[idx] == '0') next_idx = upper_bound(one.begin(), one.end(), idx) - one.begin();
                    else next_idx = upper_bound(zero.begin(), zero.end(), idx) - zero.begin();
                    if (str[idx] == '0') {
                        if (next_idx == one.size()) break;
                        idx = one[next_idx];
                        ans[idx] = cnt;
                        one.erase(one.begin() + next_idx);
                    } else {
                        if (next_idx == zero.size()) break;
                        idx = zero[next_idx]; ans[idx] = cnt;
                        zero.erase(zero.begin() + next_idx);
                    }
                }
            }
        }
        cout << cnt << nl;
        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}