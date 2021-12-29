#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n, k;
void solve(int tc) {
    cin >> n >> k; set<int> st;
    for (int i=0, a; i<n; i++) {
        cin >> a;
        st.insert(a);
    }
    int mex=n+1, mx = *st.rbegin();
    for (int i=0; i<=n; i++) {
        if (!st.count(i)) { mex = i; break; }
    }
    if (mex == n) cout << (int)st.size() + k << nl;
    else {
        if (k && !st.count((mex+mx+1)/2)) cout << st.size()+1 << nl;
        else cout << st.size() << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }