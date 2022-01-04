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
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

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

const int MM = 1000000;
stack<int> st; int n, q; int h[MM + 5]; ll psa[MM + 5];

void push (int idx) {
    while (st.size() > 1 && h[st.top()] > h[idx]) {
        int pos = st.top(); st.pop();
        psa[h[pos]] += 1LL * (pos - st.top()) * (idx - pos);
    }
    st.push(idx);
}

void solve() {

    cin >> n >> q; st.push(0);
    for (int i = 1; i <= n; i++) { cin >> h[i]; push(i); }
    while (st.size() > 1) {
        int pos = st.top(); st.pop();
        psa[h[pos]] += 1LL * (n - pos + 1) * (pos - st.top());
    }
    for (int i = 1; i <= MM; i++) { psa[i] += psa[i-1]; }
    for (int i = 1; i <= q; i++) {
        int lft, rit; cin >> lft >> rit;
        cout << psa[rit] - psa[lft-1] << nl;
    }

}

int32_t main() {
  //  ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}