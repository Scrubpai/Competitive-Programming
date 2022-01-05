#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
string s, t; set<string> st;
void solve(int tc) {
    cin >> s >> t;
    int n = t.size();
    for (int i=0; i<s.size(); i++) {
        for (int j=0; j<=n; j++) {
            string tmp = t.substr(0, j) + s[i];
            if (j<n) tmp += t.substr(j);
            st.insert(tmp);
        }
        for (int j=0; j<n; j++) {
            if (s[i] == t[j]) continue;
            string tmp = t.substr(0, j) + s[i];
            if (j<n-1) tmp += t.substr(j+1);
            st.insert(tmp);
        }
    }
    for (int i=0; i<n; i++) {
        string tmp = t.substr(0, i);
        if (i<n-1) tmp += t.substr(i+1);
        st.insert(tmp);
    }
    for (string x : st) cout << x << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }