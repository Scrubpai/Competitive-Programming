#include <bits/stdc++.h>
using namespace std;
const int MM = 1.5e6+5;
#define nl '\n'
int N, M, a[MM], freq[MM]; set<int> st;
void solve(int tc) {
    cin >> N >> M;
    for (int i=0; i<=N; i++) st.insert(i);
    int ans = N+1;
    for (int i=1; i<=N; i++) {
        cin >> a[i]; freq[a[i]]++;
        if (st.count(a[i])) st.erase(a[i]);
        if (i>=M) {
            ans = min(ans, *st.begin());
            freq[a[i-M+1]]--;
            if (!freq[a[i-M+1]]) st.insert(a[i-M+1]);
        }
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }