#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
int n; ll t; string s;
string get(string x, ll shift) {
    string ret = ""; shift %= n;
    for (int i = 0; i < n; i++) {
        if (x[(i+shift)%n] == x[(i-shift+n)%n]) ret += '0';
        else ret += '1';
    }
    return ret;
}
void solve(int tc) {
    cin >> n >> t >> s;
    for (ll i = 0; i < 64; i++) {
        if (t & (1LL << i)) {
            s = get(s, 1LL << i);
        }
    }
    cout << s << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }