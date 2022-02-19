#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;
#define f first
#define s second
const int MM = 1e6+5;
int N; vector<int> adj[MM]; ll X[MM], len1[MM], len2[MM], par[MM]; pl ans = {1e9, 1};
pl cmp(pl a, pl b) {
    if (b.f*a.s<a.f*b.s) return b;
    else return a;
}
void dfs1(int u, int pa) {
    for (int v : adj[u]) {
        if (v == pa) continue;
        dfs1(v, u);
        if (X[v] == 1) {
            if (len1[v] + 1 > len1[u]) len2[u] = len1[u], len1[u] = len1[v] + 1;
            else if (len1[v] + 1 > len2[u]) len2[u] = len1[v] + 1;
        }
    }
    ans = cmp(ans, {X[u], len1[u] + len2[u] + 1});
}
void dfs2(int u, int pa) {
    for (int v : adj[u]) {
        if (v == pa) continue;
        if (X[u] == 1) {
            if (X[v] == 1) {
                if (len1[v] + 1 == len1[u]) par[v] = max(par[u], len2[u]) + 1;
                else par[v] = max(par[u], len1[v]) + 1;
            } else {
                par[v] = max(par[u], len1[u]) + 1;
            }
            ans = cmp(ans, {X[v], par[v] + len1[v] + 1});
        }
        dfs2(v, u);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1, A, B; i<N; i++) {
        cin >> A >> B;
        adj[A].push_back(B); adj[B].push_back(A);
    }
    for (int i=1; i<=N; i++) { cin >> X[i]; ans = ans = cmp(ans, {X[i], 1}); }
    dfs1(1, 0); dfs2(1, 0);
    ll g = __gcd(ans.f, ans.s); ans.f /= g; ans.s /= g;
    cout << ans.f << '/' << ans.s << '\n';
}