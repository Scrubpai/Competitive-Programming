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
typedef double ld;
typedef long double lld;
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
const lld pi = 3.14159265358979323846;

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

const int MM = 1e5 + 5;
struct E {
    string s; int v;
};
bool cmp(E a, E b) {
    if (a.v != b.v) return a.v < b.v;
    else return a.s < b.s;
}

int T = 5; string str; stack<string> sta; unordered_map<string, int> mp;

string convert(string s) {
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == ' ') continue;
        if (s[i] < '0' || s[i] > '9') {
            string a = st.top(); st.pop(); string b = st.top(); st.pop();
            string ret = a + " " + b + " " +  s[i];
            st.push(ret);
        } else {
            st.push(s.substr(i, 1));
        }
    }
    string ans = "";
    while (!st.empty()) { ans += st.top() + " "; st.pop(); }
    return ans;
}

void solve(int tc) {

    while (T--) {
        getline(cin, str); mp.clear(); while (!sta.empty()) sta.pop();
        if (str[0] < '0' || str[0] > '9') str = convert(str);
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') continue;
            if (str[i] >= '0' && str[i] <= '9') {
                sta.push(str.substr(i, 1));
            } else {
                string a = sta.top(); sta.pop(); string b = sta.top(); sta.pop();
                string ret = b + " " + str[i] + " " + a; int v1, v2, res;
                if (!mp.count(b)) v1 = b[0] -'0';
                else v1 = mp[b];
                if (!mp.count(a)) v2 = a[0] - '0';
                else v2 = mp[a];
                if (str[i] == '*') {
                    res = v1 * v2;
                } else if (str[i] == '+') {
                    res = v1 + v2;
                } else if (str[i] == '-') {
                    res = v1 - v2;
                } else if (str[i] == '/') {
                    res = v1 / v2;
                } else {
                    res = v1 % v2;
                }
                mp[ret] = res;
                sta.push(ret);
            }
        }
        cout << mp[sta.top()] << nl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 1; //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}