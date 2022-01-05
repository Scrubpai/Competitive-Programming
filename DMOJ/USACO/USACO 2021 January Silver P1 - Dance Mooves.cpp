#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
#define nl '\n'
int N, K, c[MM], ans[MM], nxt[MM]; bool vis[MM]; unordered_set<int> st[MM];
void solve(int tc) {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) c[i] = i;
    for (int i = 1, a, b; i <= K; i++) {
        cin >> a >> b;
        st[c[a]].insert(b); st[c[b]].insert(a);
        swap(c[a], c[b]);
    }
    for (int i = 1; i <= N; i++) nxt[c[i]] = i;
    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        vector<int> v; unordered_set<int> nums;
        for (int j = i; ; j = nxt[j]) {
            if (vis[j]) break;
            vis[j] = 1; v.push_back(j); nums.insert(j);
        }
        for (int x : v) {
            for (int y : st[x]) nums.insert(y);
        }
        for (int x : v) ans[x] = nums.size();
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }