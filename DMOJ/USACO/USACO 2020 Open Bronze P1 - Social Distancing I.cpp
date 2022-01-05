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
#define f first
#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MN = 2e5 + 5;
const int MOD = 1000000;

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

int N; string str; vector<int> cows;

void add_cow() {
    int D = cows[cows.size()-1];
    cows.erase(cows.begin() + cows.size() - 1);
    if (D%2==0) {
        if (cows.size()==0) {
            D=(D-1)/2; cows.pb(D); cows.pb(D+2);
        } else {
            D/=2; cows.pb(D); cows.pb(D);
        }

    } else {
        D/=2; cows.pb(D); cows.pb(D+1);
    }
    sort(cows.begin(), cows.end());
}

void solve() {

    cin >> N >> str; int last = -1, first = -1;
    for (int i=0; i<str.size(); i++) {
        if (str[i]=='1') {
            if (last==-1) { last = i+1; first = i+1; }
            else { cows.pb(i+1-last); last = i+1; }
        }
    }
    if (last!=-1 && cows.empty()) {
        int ans = max((N-last)/2, max((last-1)/2, min(N-last, last-1)));
        cout << ans << nl;
        return;
    }
    if (cows.empty()) {
        cout << N - 1 << nl;
    } else {
        sort(cows.begin(), cows.end()); bool flag1 = false, flag2 = false;
        for (int i=1; i<=2; i++) {
            if (last != -1 && N-last >= cows[cows.size()-1]/2 && !flag1) { flag1 = true; cows.pb(N-last); sort(cows.begin(), cows.end());}
            else if (first-1 >= cows[cows.size()-1]/2 && !flag2) { flag2 = true; cows.pb(first-1); sort(cows.begin(), cows.end()); }
            else { add_cow(); }
        }

        cout << cows[0] << nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}