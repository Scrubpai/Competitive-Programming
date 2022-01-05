#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
#define nl '\n'
int Xe, Ye, N, M, C, r1, c1, r2=1e6, c2=1e6; bool r[MM], c[MM];
void solve(int tc) {
    cin >> Xe >> Ye >> N >> M >> C;
    for (int i=1, V; i<=N; i++) { cin >> V; c[V] = 1; }
    for (int i=1, H; i<=M; i++) { cin >> H; r[H] = 1; }
    for (int i=Ye; i>=0; i--) { if (r[i]) { r1=i; break; }}
    for (int i=Ye; i<=1e6; i++) { if (r[i]) { r2=i; break; }}
    for (int i=Xe; i>=0; i--) { if(c[i]) { c1=i; break; }}
    for (int i=Xe; i<=1e6; i++) { if(c[i]) { c2=i; break; }}
    for (int i=1, x, y; i<=C; i++) {
        cin >> x >> y;
        if (y>r1 && y<r2 && x>c1 && x<c2) cout << 'Y' << nl;
        else cout << 'N' << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }