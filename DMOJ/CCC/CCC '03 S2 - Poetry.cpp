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
#define lb lower_bound
#define ub upper_bound
#define mpp make_pair
#define pb push_back
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
//#define f first
//#define s second
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 10;

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

int N; string a[4]; string str;

string strtolower(string str)
{
    for(int i=0; i<str.length(); i++)
        str[i] = tolower(str[i]);
    return str;
}

void solve() {

    cin >> N; getline(cin, str);
    while (N--) {
        for (int i = 0; i < 4; i++) {
            getline(cin, str); str = strtolower(str); int pos = 0;
            for (int j = str.size() - 1; j >= 0; j--) {
                if (str[j] <= 90 && str[j] >= 65) str[j] += 32;
                if (str[j] == ' ') { pos = j + 1; break; }
                else if (j == 0 || str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u') { pos = j; break; }
            }
            a[i] = str.substr(pos, str.size() - pos);
        }
        if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) cout << "perfect" << nl;
        else if (a[0] == a[1] && a[2] == a[3]) cout << "even" << nl;
        else if (a[0] == a[2] && a[1] == a[3]) cout << "cross" << nl;
        else if (a[0] == a[3] && a[1] == a[2]) cout << "shell" << nl;
        else cout << "free" << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}