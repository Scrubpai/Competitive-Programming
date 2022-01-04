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

int T = 5;

void solve() {

    while (T--) {
        string str; getline(cin, str); bool flag = false; char prev1 = ' '; string prev2 = ""; string ans = "";
        for (int i = 0; i < str.size(); i++) {

            if (str[i] == '"' && flag && prev1 == 34) { flag = false; ans += ' '; prev1 = ' '; prev2 = ""; continue;  }
            else if (str[i] == 39 && flag && prev1 == 39) { flag = false; ans += ' '; prev1 = ' '; prev2 = ""; continue; }
            else if (str.substr(i, 2) == "*/" && prev2 == "/*" && flag) { flag = false; ans += ' '; prev1 = ' '; prev2 = ""; continue;  }


            if (flag) { ans += str[i]; continue; }

            if (str[i] == '"' && !flag) { flag = true; prev1 = '"'; prev2 = ""; }
            else if (str[i] == 39 && !flag) { flag = true; prev1 = 39; prev2 = "";  }
            else if (str.substr(i, 2) == "/*" && !flag) { flag = true; prev2 = "/*";  prev1 = ' '; i++; }
            else if (str.substr(i, 2) == "//" && !flag) { flag = true; prev1 = ' ' ; i++;  }
        }
        if (ans[ans.size()-1] == ' ') {
            for (int i = 0; i < ans.size() - 1; i++) cout << ans[i];
            cout << nl;
        } else cout << ans << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}