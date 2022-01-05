#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
typedef long long ll;
#define nl '\n'
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
int N, M, a[MM], idx[MM]; ll ans = 1; bool vis[MM];
void solve(int tc) {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) a[i] = i;
    for (int i = 1, l, r; i <= M; i++) {
        cin >> l >> r;
        swap(a[l], a[r]);
    }
    bool flag = 0;
    for (int i = 1; i <= N; i++) {
        if (a[i] != i) flag = 1;
        idx[a[i]] = i;
    }
    if (!flag) { cout << 0 << nl; return; }
    for (int i = 1; i <= N; i++) {
        if (a[i] == i) continue;
        if (!vis[i]) {
            int cnt = 0;
            for (int j = i; ; j = idx[j]) { if (vis[j]) break; cnt++; vis[j] = 1; }
            ans = lcm(ans, cnt);
        }
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}