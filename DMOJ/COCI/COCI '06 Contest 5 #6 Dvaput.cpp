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
#define mpp make_pair
#define pb push_back
#define AUT auto
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 1e9 + 7;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;

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
struct pair_hash {
    inline std::size_t operator()(const std::pair<ll,ll> & v) const {
        return v.first*31+v.second;
    }
};

const int MM = 2e5 + 5;
int L; string str; unordered_set<pll, pair_hash> st;
ll hsh1[MM], hsh2[MM], p1[MM], p2[MM], base1 = 131, base2 = 31;

ll getSubstr1(int l, int r) { return ((hsh1[r] - hsh1[l-1] * p1[r-l+1]) % MOD1 + MOD1) % MOD1; }
ll getSubstr2(int l, int r) { return ((hsh2[r] - hsh2[l-1] * p2[r-l+1]) % MOD2 + MOD2) % MOD2; }

void solve() {

    cin >> L >> str; p1[0] = 1; p2[0] = 1;
    for (int i = 1; i <= L; i++) {
        p1[i] = (p1[i-1] * base1) % MOD1;
        p2[i] = (p2[i-1] * base2) % MOD2;
        hsh1[i] = (hsh1[i-1] * base1 + str[i-1]) % MOD1;
        hsh2[i] = (hsh2[i-1] * base2 + str[i-1]) % MOD2;
    }
    int ans = 0;
    int lo = 1, hi = L - 1;
    while (lo <= hi) {
        st.clear();
        int mid = (lo + hi) / 2;
        bool flag = 0;
        for (int i = mid; i <= L; i++) {
            ll cur_hash1 = getSubstr1(i - mid + 1, i); ll cur_hash2 = getSubstr2(i - mid + 1, i);
            if (st.count({cur_hash1, cur_hash2})) { flag = 1; break; }
            st.insert({cur_hash1, cur_hash2});
        }
        if (flag) ans = max(ans, mid), lo = mid + 1;
        else hi = mid - 1;
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}