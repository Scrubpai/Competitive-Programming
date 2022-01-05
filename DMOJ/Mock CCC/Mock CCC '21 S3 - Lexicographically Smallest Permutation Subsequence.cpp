#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
#define nl '\n'
int N, K, a[MM], last[MM], st[MM], top, vis[MM];
void solve(int tc) {
    cin >> N >> K;
    for (int i=1; i<=N; i++) { cin >> a[i]; last[a[i]] = i; }
    int l = -1;
    for (int i=1; i<=N; i++) {
        if (vis[a[i]]) {
            if (last[a[i]]==i) l = max(l, vis[a[i]]);
            continue;
        }
        while (top && a[i]<=a[st[top]]) {
            if (st[top] <= l) break;
            vis[a[st[top]]] = 0; top--;
        }
        vis[a[i]] = i;
        st[++top] = i;
        if (last[a[i]] == i) l = i;
    }
    cout << a[st[1]];
    for (int i=2; i<=K; i++) cout << ' ' << a[st[i]];
    cout << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }