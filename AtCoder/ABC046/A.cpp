#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int a, b, c; set<int> st;
void solve(int tc) {
    cin >> a >> b >> c;
    st.insert(a); st.insert(b); st.insert(c);
    cout << st.size() << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}