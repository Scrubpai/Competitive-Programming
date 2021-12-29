#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 1e5 + 5;
int n, q, p[MM]; set<int> st; map<int, int> mp;

void solve(int tc) {

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        st.insert(p[i]);
    }
    sort(p + 1, p + 1 + n);
    for (int i = 2; i <= n; i++) {
        mp[p[i]-p[i-1]]++;
    }
    if (st.size() <= 2) cout << 0 << nl;
    else {
        auto itt = mp.rbegin();
        int lo = *st.begin(), hi = *st.rbegin();
        cout << -(itt->first) + hi - lo << nl;
    }
    for (int i = 1, t, x; i <= q; i++) {
        cin >> t >> x;
        if (t == 0) {
            auto it = st.lower_bound(x);
            if (it != st.begin() && st.size() > 1) {
                auto it2 = it; it2--;
                int dif = *it - *it2;
                mp[dif]--;
                if (!mp[dif]) mp.erase(dif);
            }
            if (it != st.end() && st.size() > 1) {
                auto it3 = it; it3++;
                int dif = *it3 - *it;
                mp[dif]--;
                if (!mp[dif]) mp.erase(dif);
            }
            st.erase(x);
            if (st.size() > 1) {
                it = st.lower_bound(x);
                if (it != st.begin()) {
                    auto it2 = it; it2--;
                    int dif = *it - *it2;
                    mp[dif]++;
                }
            }
        } else {
            if (st.size() > 1) {
                auto it = st.lower_bound(x);
                if (it != st.begin()) {
                    auto it2 = it; it2--;
                    int dif = *it - *it2;
                    mp[dif]--;
                    if (!mp[dif]) mp.erase(dif);
                }
            }
            st.insert(x);
            if (st.size() > 1) {
                auto it = st.lower_bound(x);
                if (it != st.begin()) {
                    auto it2 = it; it2--;
                    int dif = *it - *it2;
                    mp[dif]++;
                }
                if (it != st.end()) {
                    auto it3 = it; it3++;
                    int dif = *it3 - *it;
                    mp[dif]++;
                }
            }
        }
        if (st.size() <= 2) cout << 0 << nl;
        else {
            auto it = mp.rbegin();
            int lo = *st.begin(), hi = *st.rbegin();
            cout << -(it->first) + hi - lo << nl;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}