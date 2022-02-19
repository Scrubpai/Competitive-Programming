#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
typedef pair<int, int> pii;
#define f first
#define s second
int N, K, lo[MM], hi[MM]; vector<int> skill; vector<pii> adj[MM];
int get(int l, int r) {
    int a = lower_bound(skill.begin(), skill.end(), l) - skill.begin(), b = upper_bound(skill.begin(), skill.end(), r) - skill.begin();
    return b - a;
}
void dfs(int u, int pa) {
    vector<pii> vals;
    for (pii p : adj[u]) {
        int v = p.first, d = p.second;
        if (v == pa) continue;
        vals.push_back({d, v});
    }
    sort(vals.begin(), vals.end());
    for (int i=0; i<(int)vals.size(); i++) {
        int d = vals[i].f, v = vals[i].s;
        if (vals.size() > 1) {
            int l, r;
            if (!i) {
                l = 1; r = d+(vals[i+1].f-d)/2;
            } else if (i==(int)vals.size()-1) {
                l = d-(d-vals[i-1].f-1)/2; r = 1e9;
            } else {
                l = d-(d-vals[i-1].f-1)/2; r = d+(vals[i+1].f-d)/2;
            }
            lo[v] = max(lo[u], l);
            hi[v] = min(hi[u], r);
        } else {
            lo[v] = lo[u];
            hi[v] = hi[u];
        }
        dfs(v, u);
    }
}
int ans(int i) {
    if (lo[i] > hi[i]) return 0;
    else return get(lo[i], hi[i]);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K;
    for (int i=1, a, b, d; i<N; i++) {
        cin >> a >> b >> d;
        adj[a].push_back({b, d}); adj[b].push_back({a, d});
    }
    for (int i=0, x; i<K; i++) {
        cin >> x;
        skill.push_back(x);
    }
    sort(skill.begin(), skill.end());
    lo[1] = 1; hi[1] = 1e9;
    dfs(1, 0);
    cout << ans(1);
    for (int i=2; i<=N; i++) cout << ' ' << ans(i);
    cout << '\n';
}