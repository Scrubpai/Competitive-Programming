#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
#define f first
#define s second
ll sum(ll n) {
    return n*(n+1)/2;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    for (int tt=0, n; tt<t; tt++) {
        cin >> n; vector<int> k(n), h(n); stack<pi> st;
        for (int i=0; i<n; i++) cin >> k[i];
        for (int i=0; i<n; i++) cin >> h[i];
        st.push({k[0] - h[0], k[0]}); //{left, right}
        for (int i=1; i<n; i++) {
            int lft = k[i] - h[i], rit = k[i], minimum = lft;
            while (!st.empty() && st.top().s > lft) minimum = min(minimum, st.top().f), st.pop();
            st.push({minimum, rit});
        }
        ll ans = 0;
        while (!st.empty()) {
            ans += sum(st.top().s - st.top().f);
            st.pop();
        }
        cout << ans << '\n';
    }
}