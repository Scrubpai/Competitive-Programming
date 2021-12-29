#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    for (int tt=0, n; tt<t; tt++) {
        cin >> n;
        vector<ll> cnt(n+1), ans(n+1);
        for (int i=0, x; i<n; i++) {
            cin >> x;
            cnt[x]++;
        }
        cout << cnt[0]; ans[0] = cnt[0];
        stack<int> st;
        for (int i=1; i<=n; i++) {
            if (ans[i-1] == -1) ans[i] = -1;
            else {
                for (int j=0; j<cnt[i-1]; j++) st.push(i-1);
                if (st.empty()) ans[i] = -1;
                else {
                    ans[i] = ans[i-1] + i-st.top()-1 + cnt[i] - cnt[i-1];
                    st.pop();
                }
            }
            cout << " " << ans[i];
        }
        cout << '\n';
    }
}