#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100001;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
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
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
#define f first
#define s second
#define nl '\n'

string str;
bool check(string a, string b) {
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    if (a==b) return true;
    else return false;
}

void rec(string cur, string s) {
    if (cur.size()==s.size()) {
        if (check(cur, s)) cout << cur << endl;
        return;
    }
    for (char c='a'; c<='z'; c++) {
        rec(cur+c, s);
    }
}

void solve() {

    for (int i=0; i<5; i++) {
        cin >> str;
        rec("", str);
    }

}

int32_t main() {
  //  ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}