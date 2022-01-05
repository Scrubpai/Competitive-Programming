#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 1e5 + 5;
struct req {
    char c; int x, i;
};
bool cmp(req a, req b) { return a.i > b.i; }
int n, m, pre[26], cnt[26], freq[26]; vector<req> a; char ch, ans[MM], idk[MM]; set<int> st;

void solve(int tc) {

    cin >> n >> m;
    for (int i = 1, x, j; i <= m; i++) {
        cin >> ch >> x >> j;
        if (j < x) { cout << -1 << nl; return; }
        a.push_back({ch, x, j});
    }
    sort(a.begin(), a.end(), cmp);
    for (req r : a) cnt[r.c-'a']++;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
        for (char c = 'a'; c <= 'z'; c++) {
            if (cnt[c-'a'] == 0) { idk[i] = c; break; }
        }
        while (!a.empty() && a.back().i == i) {
            req r = a.back(); a.pop_back();
            int num = r.x, v = r.c - 'a'; cnt[v]--;
            if (freq[v] > num) { cout << -1 << nl; return; }
            num -= freq[v];
            while (!st.empty() && num > 0) {
                auto it = st.upper_bound(pre[v]);
                if (it != st.end()) {
                    num--; ans[*it] = r.c; st.erase(it);
                }
            }
            if (num > 0) { cout << -1 << nl; return; }
            freq[v] = r.x; pre[v] = r.i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] < 'a' || ans[i] > 'z') {
            if (idk[i] < 'a' || idk[i] > 'z') { cout << -1 << nl; return; }
            else ans[i] = idk[i];
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i];

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}