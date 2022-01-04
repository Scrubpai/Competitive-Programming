#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pi;
typedef pair<int, int> pii;
#define endl '\n'
#define INF 0x3f3f3f3f
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mpp make_pair
#define pb push_back
#define f first
#define s second
#define nl '\n'
const int NM = 10000;

int N; vector<int> adj[3]; vector<int> ans;

void print(vector<int> &b){
    printf("%d%c", b.back(), (N==0? '\n': ' ')); b.pop_back();
}

void solve() {
    cin >> N;
    for (int i=0, x; i<N; i++) { cin >> x; adj[x%3].pb(x); }

    if (adj[0].size()>adj[1].size()+adj[2].size()+1 || (adj[0].empty()&&!adj[1].empty()&&!adj[2].empty())) { cout << "impossible" << nl; return; }
    while (!adj[1].empty()) {
        if (adj[0].size()>adj[1].size()) {
            N--; print(adj[0]); N--; print(adj[1]);
        } else {
            N--; print(adj[1]);
        }
    }
    while (!adj[2].empty()) {
        if (!adj[0].empty()) {
            N--; print(adj[0]); N--; print(adj[2]);
        } else {
            N--; print(adj[2]);
        }
    }
    if (!adj[0].empty()) { N--; print(adj[0]); }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}