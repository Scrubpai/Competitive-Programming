#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 1e5 + 5;
int N, M, dsu[MM], xmin[MM], xmax[MM], ymin[MM], ymax[MM];

int Find(int x) {
    if (dsu[x] == x) return x;
    else return dsu[x] = Find(dsu[x]);
}

void solve(int tc) {

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> xmin[i] >> ymin[i];
        xmax[i] = xmin[i]; ymax[i] = ymin[i];
        dsu[i] = i;
    }
    for (int i = 1, a, b; i <= M; i++) {
        cin >> a >> b;
        int fa = Find(a), fb = Find(b);
        if (fa != fb) {
            dsu[fa] = fb;
            xmin[fb] = min(xmin[fb], xmin[fa]);
            xmax[fb] = max(xmax[fb], xmax[fa]);
            ymin[fb] = min(ymin[fb], ymin[fa]);
            ymax[fb] = max(ymax[fb], ymax[fa]);
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= N; i++) {
        int v = Find(i);
        ans = min(ans, 2 * (xmax[v] - xmin[v]) + 2 * (ymax[v] - ymin[v]));
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}