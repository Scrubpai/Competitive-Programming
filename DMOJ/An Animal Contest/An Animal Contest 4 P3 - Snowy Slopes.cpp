#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;
const int MM = 1e5+5;
int N, M; ll x[MM], y[MM], k[MM], d[MM]; unordered_map<ll, int> mp; set<pl> st;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> x[i] >> y[i];
    ll ans = 0;
    for (int i=1; i<=M; i++) {
        cin >> k[i] >> d[i]; mp.clear();
        ll g = __gcd(k[i], d[i]);
        k[i] /= g; d[i] /= g;
        if (st.count({k[i], d[i]})) continue;
        st.insert({k[i], d[i]});
        for (int j=1; j<=N; j++) {
            ll v = d[i]*y[j]-k[i]*x[j];
            ans += mp[v];
            mp[v]++;
        }
    }
    cout << ans << '\n';
}