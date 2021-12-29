#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+5;
int N, Q, dsu[MM], sz[MM]; ll a[MM];
int fd(int x) { if (dsu[x] == x) return x; else return dsu[x] = fd(dsu[x]); }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> Q;
    for (int i=1; i<=N; i++) { dsu[i] = i; sz[i] = 1; cin >> a[i]; }
    for (int i=1, op, x, y; i<=Q; i++) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            int fx = fd(x), fy = fd(y);
            if (fx != fy) dsu[fx] = fy, sz[fy] += sz[fx], a[fy] += a[fx];
        } else {
            cin >> x;
            if (op == 2) cout << sz[fd(x)] << '\n';
            else cout << a[fd(x)] << '\n';
        }
    }
}