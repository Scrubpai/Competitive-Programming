#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

const int MM = 2e5 + 5;
int n, b[MM]; unordered_set<int> st;

void solve(int tc) {

    cin >> n; st.clear();
    bool flag = 0;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (st.count(b[i]) && !flag) { cout << "YES" << nl; flag = 1; }
        st.insert(b[i]);
    }
    if (!flag) cout << "NO" << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}