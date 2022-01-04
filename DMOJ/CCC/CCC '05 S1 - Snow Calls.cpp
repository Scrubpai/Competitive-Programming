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
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
#define f first
#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MN = (int)4e5 + 5;
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

unordered_map<char, int> mp;

void solve() {

    char c = 'A';
    for (int i=2; i<=9 && c<='Z'; i++, c+=3) {
        mp[c] = i; mp[c+1] = i; mp[c+2] = i;
        if (i==7 || i==9) {mp[c+3] = i; c++; }
    }

    int t; cin >> t;
    while (t--) {
        string str; cin >> str; int cnt = 0; int cnt2=0; int cnt3=0;
        rep(i, 0, str.size()) {
            if (str[i]=='-') continue;
            else cnt3++;
            if (cnt3>10) break;

            if (!mp.count(str[i])) cout << str[i];
            else cout << mp[str[i]];
            cnt++;
            if (cnt==3 && cnt2<2) { cnt2++; cnt = 0; cout << "-";}
        }
        cout << nl;
    }

}

int32_t main() {
   // ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}