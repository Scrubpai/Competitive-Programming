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
#define mpp make_pair
#define pb push_back
#define AUT auto
#define nl '\n'
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll pwmd(ll b, ll exp) {
    ll ret = 1;
    while (exp > 0) {
        if (exp % 2 == 1) ret = (ret * b) % MOD;
        exp /= 2;
        b = (b * b) % MOD;
    }
    return ret;
}

string str; ll ans;

bool vowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

bool cons(char c) {
    return c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U';
}

void fun(string s, bool L, int cntC, int cntV, int cntL) {
    if (s.find('_') == -1) {
        if (!L) return;
        for (int i = 2; i < s.size(); i++) {
            if ((vowel(s[i]) && vowel(s[i-1]) && vowel(s[i-2])) || (cons(s[i]) && cons(s[i-1]) && cons(s[i-2]))) return;
        }
        if (cntC == 0 && cntV != 0) {
            ans += (1LL * pow(5, cntV));
        } else if (cntC != 0 && cntV != 0) {
            ans += (1LL * pow(5, cntV) * pow(20, cntC));
        } else {
            ans++; //all Ls
        }
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '_') {
            s[i] = 'L';
            fun(s, 1, cntC, cntV, cntL + 1);
            s[i] = 'A';
            fun(s, L, cntC, cntV + 1, cntL);
            s[i] = 'B';
            fun(s, L, cntC + 1, cntV, cntL);
            s[i] = '_';

            return;
        }
    }
}

void solve() {

    cin >> str;
    bool flag = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'L') { flag = 1; break; }
    }
    fun(str, flag, 0, 0, 0);
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}