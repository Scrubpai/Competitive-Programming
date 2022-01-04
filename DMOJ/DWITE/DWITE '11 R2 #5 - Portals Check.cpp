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
const int MN = 100005;
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

unordered_map<string, int> mp; int dsu[MN];

int Find(int x) {
    if (dsu[x]==x) return x;
    else return dsu[x] = Find(dsu[x]);
}

void solve() {

    int t = 5;
    while (t--) {
        int N; cin >> N; int cnt=1;
        mp.clear(); for (int i=1; i<=N; i++) dsu[i] = i;
        rep(i, 0, N) {
            char ch; cin >> ch;
            string a, b; cin >> a >> b; int p1, p2;
            if (!mp.count(a)) mp[a] = cnt++;
            if (!mp.count(b)) mp[b] = cnt++;
            if (ch=='p') {
                p1 = mp[a]; p2 = mp[b];
                int fp1 = Find(p1); int fp2 = Find(p2);
                if (fp1!=fp2) dsu[fp1] = fp2;
            } else {
                p1 = mp[a]; p2 = mp[b];
                int fp1 = Find(p1); int fp2 = Find(p2);
                if (fp1!=fp2) cout << "not connected" << nl;
                else cout << "connected" << nl;
            }
        }
    }

}

int32_t main() {
   // ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}