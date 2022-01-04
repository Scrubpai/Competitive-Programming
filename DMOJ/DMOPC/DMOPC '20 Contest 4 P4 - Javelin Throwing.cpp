#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e6+5;
#define nl '\n'
ll N, a[MM];
void solve(int tc) {
    cin >> N;
    stack<int> st;
    ll tot = 0, sum = 0, mx = 0;
    for (int i=1; i<=N; i++) {
        cin >> a[i];
        if (a[i] + 1 > mx) {
            for (int j=0; j< a[i] - mx; j++) {
                tot += i - st.top();
                st.pop();
            }
            mx = a[i] + 1;
        } else st.push(i);
        tot += mx; sum += a[i];
        if (i==1) cout << tot - sum - i;
        else cout << " " << tot - sum - i;
    }
    cout << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }