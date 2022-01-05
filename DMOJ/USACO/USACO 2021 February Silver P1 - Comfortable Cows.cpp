#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
const int MM = 3001;
typedef pair<int, int> pii;
int N, adj[MM][MM], ans; bool cow[MM][MM];
vector<pii> genAdj(int x, int y) { return {{x-1, y}, {x, y-1}, {x+1, y}, {x, y+1}}; }
pii notAdj(int x, int y) { for(auto i:genAdj(x, y)) if(!cow[i.first][i.second]) return i;}
void dfs(int x, int y) {
    if (cow[x][y]) return;
    cow[x][y] = 1; ans++;
    for (pii p : genAdj(x, y)) adj[p.first][p.second]++;
    for (pii p : genAdj(x, y)) if (cow[p.first][p.second] && adj[p.first][p.second] == 3) dfs(notAdj(p.first, p.second).first, notAdj(p.first, p.second).second);
    if (adj[x][y] == 3) dfs(notAdj(x, y).first, notAdj(x, y).second);
}
void solve(int tc) {
    cin >> N;
    for (int i=1, x, y; i<=N; i++) {
        cin >> x >> y;
        x += 1400; y += 1400;
        dfs(x, y);
        cout << ans - i << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }