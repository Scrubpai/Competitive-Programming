#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
#define nl '\n'
int N; bool vis[MM];
void solve(int tc) {
    cin >> N;
    for (int i=1, L; i<=N; i++) {
        cin >> L;
        vis[L] = 1;
    }
    for (int i=1; i<=N; i++) {
        if (!vis[i]) { cout << "NO" << nl; return; }
    }
    cout << "YES" << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }