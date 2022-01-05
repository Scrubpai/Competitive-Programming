#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define nl '\n'
int V, T, R1, R2, W, dp[30][35][35]; unordered_map<char, int> variables, terminals; vector<int> vt[30]; vector<pii> vv[30];
int fun(int idx, int l, int r, string &s) {
    if (l == r) {
        for (int t : vt[idx]) {
            if (terminals[s[l]] == t) return 1;
        }
        return 0;
    }
    if (dp[idx][l][r] != -1) return dp[idx][l][r];
    dp[idx][l][r] = 0;
    for (pii p : vv[idx]) {
        int a = p.first, b = p.second;
        for (int k=l; k<r; k++) {
            dp[idx][l][r] = max(dp[idx][l][r], min(fun(a, l, k, s), fun(b, k+1, r, s)));
        }
    }
    return dp[idx][l][r];
}
void solve(int tc) {
    cin >> V >> T;
    for (int i=0; i<V; i++) {
        char c; cin >> c;
        variables[c] = i;
    }
    for (int i=0; i<T; i++) {
        char c; cin >> c;
        terminals[c] = i;
    }
    cin >> R1;
    for (int i=0; i<R1; i++) {
        char v, t; cin >> v >> t;
        vt[variables[v]].push_back(terminals[t]);
    }
    cin >> R2;
    for (int i=0; i<R2; i++) {
        char v, v1, v2; cin >> v >> v1 >> v2;
        vv[variables[v]].emplace_back((make_pair(variables[v1], variables[v2])));
    }
    cin >> W;
    for (int i=0; i<W; i++) {
        string s; cin >> s;
        memset(dp, -1, sizeof(dp));
        cout << fun(0, 0, (int)s.size()-1, s) << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }