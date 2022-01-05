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
const int MN = 1e6 + 5;
const int MOD = 998244353;

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

int n, freq[26], lcs; string str;

void solve() {

    cin >> n >> lcs >> str;
    for (char c : str) freq[c-'a']++;
    int mi = n+1; char c = ' ';
    for (int i=0; i<26; i++) {
        if (freq[i] < mi) { mi = freq[i]; c = i + 'a'; }
    }
    if (mi > lcs || lcs > n) { cout << "WRONGANSWER" << nl; return; }
    for (int i=0; i<str.size(); i++) {
        if (mi < lcs) {
            cout << str[i];
            if (str[i]!=c) mi++;
        } else cout << c;
    }
    cout << nl;

}

int32_t main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}