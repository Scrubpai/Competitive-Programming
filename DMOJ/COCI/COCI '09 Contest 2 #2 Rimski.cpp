#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 10000;
typedef long long ll;
typedef pair<int, int> pi;
#define endl '\n'
#define INF 0x3f3f3f3f
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mpp make_pair
#define pb push_back
#define sz(a) sizeof(a)/sizeof(a[0])
#define AUT auto

string R, ans;
string digit[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
string ten[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};

int string2int(string s) {
    int ret = 0;
    for (int i=9; i>=1; i--) {
        if (s.substr(0, ten[i].size())==ten[i]) {
            ret += i*10; s = s.substr(ten[i].size()); break;
        }
    }

    for (int i=9; i>=1; i--) {
        if (digit[i]==s) {
            ret += i; break;
        }
    }
    return ret;
}

string int2string(int x) {
    return ten[x/10] + digit[x%10];
}

bool check(string a, string b) {
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    return a==b;
}

void solve() {

    cin >> R; ans = R;
    int x = string2int(R);

    for (int i=x; i>=1; i--) {
        string R2 = int2string(i);
        if (check(R, R2)) ans = R2;
    }

    cout << ans << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}