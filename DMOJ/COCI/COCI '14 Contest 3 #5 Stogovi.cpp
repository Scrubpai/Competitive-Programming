#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))

const int MM = 3e5 + 5;
const int MX = 19;
int n, anc[MM][MX+5], dep[MM], v, mp[MM], w; char c;

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    int d = dep[a] - dep[b];
    while (d > 0) {
        int i = log2(d);
        a = anc[a][i];
        d -= (1 << i);
    }
    if (a == b) return a;
    for (int i = MX; i >= 0; i--) {
        if (anc[a][i] != -1 && anc[b][i] != -1 && anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
    }
    return anc[a][0];
}

void solve(int tc) {

    cin >> n; ms(anc, -1);
    for (int i = 1; i <= n; i++) {
        cin >> c;
        if (c == 'a') {
            cin >> v; v = mp[v];
            dep[i] = dep[v] + 1; mp[i] = i; anc[i][0] = v;
            for (int j = 1; j <= MX; j++) {
                int par = anc[i][j-1];
                if (par != -1) anc[i][j] = anc[par][j-1];
            }
        } else if (c == 'b') {
            cin >> v; v = mp[v];
            cout << v << nl;
            mp[i] = anc[v][0];
        } else {
            cin >> v >> w;
            v = mp[v]; w = mp[w]; mp[i] = v;
            cout << dep[lca(v, w)] << nl;
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