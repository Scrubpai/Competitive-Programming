#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 2e5+5;
#define nl '\n'
struct node { int l, r, v; } seg[3*MM];
int N, W, D, S[MM], dis[MM]; vector<int> adj[MM];
void pushup(int rt) { seg[rt].v = min(seg[2*rt].v, seg[2*rt+1].v); }
void build(int l, int r, int rt) {
    seg[rt].l = l; seg[rt].r = r;
    if (l == r) { seg[rt].v = l-1+dis[S[l]]; return; }
    int mid = (l + r) / 2;
    build(l, mid, 2*rt); build(mid+1, r, 2*rt+1); pushup(rt);
}
void update(int p, int v, int rt) {
    if (seg[rt].l == seg[rt].r) { seg[rt].v = v; return; }
    int mid = (seg[rt].l + seg[rt].r) / 2;
    if (p <= mid) update(p, v, 2*rt);
    else update(p, v, 2*rt+1);
    pushup(rt);
}
void solve(int tc) {
    cin >> N >> W >> D;
    for (int i=1, A, B; i<=W; i++) {
        cin >> A >> B;
        adj[B].push_back(A);
    }
    for (int i=1; i<=N; i++) { cin >> S[i]; dis[i]=1e9; }
    queue<int> q; dis[N] = 0; q.push(N);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int v : adj[cur]) {
            if (dis[v] == (int)1e9) {
                dis[v] = dis[cur] + 1; q.push(v);
            }
        }
    }
    build(1, N, 1);
    for (int i=1, X, Y; i<=D; i++) {
        cin >> X >> Y;
        swap(S[X], S[Y]); update(X, X-1+dis[S[X]], 1); update(Y, Y-1+dis[S[Y]], 1);
        cout << seg[1].v << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }