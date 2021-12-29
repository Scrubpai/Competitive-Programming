#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
string s; stack<char> st;
void solve(int tc) {
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '<' || s[i] == '{' || s[i] == '(' || s[i] == '[') st.push(s[i]);
        else {
            if (st.empty()) { cout << "Impossible" << nl; return; }
            char c = st.top(); st.pop();
            if ((c == '<' && s[i] != '>') || (c == '(' && s[i] != ')') || (c == '{' && s[i] != '}') || (c == '[' && s[i] != ']')) ans++;
        }
    }
    if (!st.empty()) cout << "Impossible" << nl;
    else cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1;// cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}