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

const int MM = 1005;
int r, c, a[MM][MM], hist[MM], ans;

int maxRectInHist(int hist[]) {
    stack<int> st; int area = 0;
    for (int i = 0; i < c - 1; i++) {
        while (!st.empty() && hist[i] <= hist[st.top()]) {
            int idx = st.top(); st.pop(); int j = -1; if (!st.empty()) j = st.top();
            area = max(area, (i - j) * (hist[idx]+1));
        }
        st.push(i);
    }
    while (!st.empty()) {
        int idx = st.top(); st.pop(); int j = -1; if (!st.empty()) j = st.top();
        area = max(area, (c - j - 1) * (hist[idx] + 1));
    }
    return area;
}

void solve() {

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r- 1; i++) {
        for (int j = 0; j < c - 1; j++) {
            if (a[i][j] + a[i+1][j+1] <= a[i+1][j] + a[i][j+1]) hist[j]++;
            else hist[j] = 0;
        }
        ans = max(ans, maxRectInHist(hist));
    }
    cout << ans << nl;

}

int32_t main() {
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}