#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N, T, num[105], mx, rem[105]; vector<array<int, 3>> events; bool res[105], infected[105]; string str;
void solve(int tc) {
    cin >> N >> T >> str;
    for (int i = 0; i < N; i++) res[i+1] = (str[i]-'0') == 1;
    for (int i = 1, t, x, y; i <= T; i++) {
        cin >> t >> x >> y;
        events.push_back({t, x, y});
        num[x]++; num[y]++;
        mx = max({mx, num[x], num[y]});
    }
    int cnt = 0, y = 1e9, z = -1; sort(events.begin(), events.end());
    for (int i = 1; i <= N; i++) {
        bool counted = 0;
        for (int k = 0; k <= mx+1; k++) {
            for (int j = 1; j <= N; j++) rem[j] = k, infected[j] = 0;
            infected[i] = 1;
            for (array<int, 3> a : events) {
                auto [t, u, v] = a;
                bool f1 = infected[u], f2 = infected[v];
                if (f1 && rem[u]) infected[v] = 1, rem[u]--;
                if (f2 && rem[v]) infected[u] = 1, rem[v]--;
            }
            bool flag = 1;
            for (int j = 1; j <= N; j++) {
                if (infected[j] != res[j]) { flag = 0; break; }
            }
            if (flag && !counted) counted = 1, cnt++;
            if (flag) y = min(y, k), z = max(z, k);
        }
    }
    cout << cnt << " " << y << " ";
    if (z == mx + 1) cout << "Infinity";
    else cout << z;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc; */ for (int t = 1; t <= tc; t++) solve(t); return 0; }