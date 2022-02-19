#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
struct E { int w, a[4]; } e[MM];
int N, dsu[2*MM], ans;
int fd(int x) { if (dsu[x] == x) return x; else return dsu[x] = fd(dsu[x]); }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1; i<=2*N; i++) dsu[i] = i;
    for (int i=1; i<=N; i++) {
        cin >> e[i].w;
        for (int j=0; j<2; j++) {
            cin >> e[i].a[2*j] >> e[i].a[2*j+1];
            dsu[fd(e[i].a[2*j])] = fd(e[i].a[2*j+1]);
        }
    }
    sort(e+1, e+1+N, [](E a, E b) { return a.w < b.w; });
    for (int i=1; i<=N; i++) {
        int fa = fd(e[i].a[0]), fb = fd(e[i].a[2]);
        if (fa != fb) { dsu[fa] = fb; ans += e[i].w; }
    }
    cout << ans << '\n';
}