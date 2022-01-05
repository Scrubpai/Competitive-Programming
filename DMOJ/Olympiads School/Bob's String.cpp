#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<string> vs;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
#define f first
#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MN = (int)1e6 + 5;
const ll MOD = 998244353;

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

deque<char> dq;  int N; string ans = "";

int fun() {
    deque<char> newdq = dq; int num = 1;
    while (!dq.empty()) {
        char a = newdq.front(); char b = newdq.back();
        if (a!=b) {
            if (a<b) num = 1;
            else num = 2;
            break;
        } else {
            if (newdq.size()>1) { newdq.pop_back(); newdq.pop_front(); }
            else newdq.pop_front();
        }
    }
    return num;
}

void solve() {

    cin >> N;
    rep(i, 0, N) {
        char ch; cin >> ch; dq.push_back(ch);
    }
    while (!dq.empty()) {
        char a = dq.front(); char b = dq.back(); //cout << a << " " << b << nl;
        if (a<b) { ans+=a; dq.pop_front(); }
        else if (b<a) { ans+=b; dq.pop_back(); }
        else {
            int x = fun();
            if (x==1) { ans+=a; dq.pop_front(); }
            else { ans+=b; dq.pop_back(); }
        }
    }
    cout << ans << nl;

}

int32_t main() {
   // ios_base::sync_with_stdio(false);
   // cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}