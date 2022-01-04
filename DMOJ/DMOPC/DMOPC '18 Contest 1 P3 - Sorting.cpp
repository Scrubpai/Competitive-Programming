#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N, P[105]; bool vis[105]; vector<int> cycle, ord;
void solve(int tc) {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> P[i];
    for (int i = 1; i <= N; i++) {
        if (P[i] == i) continue;
        if (!vis[i]) {
            cycle.push_back(i);
            ord.clear();
            for (int j = i; ;j = P[j]) {
                if (vis[j]) break;
                ord.push_back(j); vis[j] = 1;
            }
        }
    }
    if (cycle.empty()) cout << 0 << nl;
    else if (cycle.size() == 1) {
        cout << 1 << nl << ord.size();
        for (int x : ord) cout << " " << x;
        cout << nl;
    } else {
        cout << 2 << nl << cycle.size();
        for (int x : cycle) cout << " " << x;
        cout << nl;
        int last = P[cycle[cycle.size()-1]];
        for (int i = cycle.size() - 1; i > 0; i--) P[cycle[i]] = P[cycle[i-1]];
        P[cycle[0]] = last;
        memset(vis, 0, sizeof(vis)); ord.clear();
        for (int i = 1; i <= N; i++) {
            if (P[i] == i) continue;
            if (!vis[i]) {
                for (int j = i; ; j = P[j]) {
                    if (vis[j]) break;
                    ord.push_back(j); vis[j] = 1;
                }
            }
        }
        cout << ord.size();
        for (int x : ord) cout << " " << x;
        cout << nl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}