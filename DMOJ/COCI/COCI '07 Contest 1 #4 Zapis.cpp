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
#define rep(i,a,n) for (int i=a;i<n;i++)
#define rep1(i, a, n) for (int i=a; i<=n; i++)
#define per(i,a,n) for (int i=a-1;i>=n;i--)
#define per1(i,a,n) for (int i=a;i>=n;i--)
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
typedef unsigned long long ull;
const int MN = 1e6 + 5;
const int MOD = 100000;

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

int n; string str; ll dp[205][205]; set<string> st; bool flag;

void solve() {

    cin >> n >> str; str = " " + str;
    st.insert("()"); st.insert("{}"); st.insert("[]");
    st.insert("?]"); st.insert("?}"); st.insert("?)");
    st.insert("(?"); st.insert("[?"); st.insert("{?");
    for (int i = 1; i < n; i++) {
        if (st.count(str.substr(i, 2))) dp[i][i+1] = 1;
        else if (str.substr(i, 2) == "??") dp[i][i+1] = 3;
    }

    for (int i = 1; i <= n + 2; i++) dp[i][i - 1] = 1;
    for (int len = 3; len < n; len+=2) {
        for (int i = 1; i + len <= n; i++) {
            int lft = i, rit = i + len;

            string tmp = "";
            tmp = tmp + str[lft] + str[rit];
            if (st.count(tmp)) dp[lft][rit] = dp[lft+1][rit-1];
            else if (str[lft] == '?' && str[rit] == '?' && dp[lft+1][rit-1] != 0) dp[lft][rit] = (dp[lft+1][rit-1] * 3);

            for (int k = lft + 1; k < rit; k+=2) {
                string tmp = ""; tmp = tmp + str[lft] + str[k];
                if (st.count(tmp)) dp[lft][rit] = (dp[lft][rit] + dp[lft+1][k-1] * dp[k+1][rit]);
                else if (str[lft] == str[k] && str[lft] == '?') dp[lft][rit] = (dp[lft][rit] + 3 * dp[lft+1][k-1] * dp[k+1][rit]);

                if (lft == 1 && rit == n && dp[lft][rit] >= MOD) flag = true;
                dp[lft][rit] %= MOD;
            }
        }
    }

    if (flag) printf("%05lld\n", dp[1][n]);
    else cout << dp[1][n] << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}