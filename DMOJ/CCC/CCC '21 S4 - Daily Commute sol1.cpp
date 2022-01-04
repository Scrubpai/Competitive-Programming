#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 2e5+5;
#define nl '\n'
int N, W, D, S[MM], dis[MM]; vector<int> adj[MM]; set<pi> st;
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
    for (int i=1; i<=N; i++) st.insert({i-1 + dis[S[i]], i});
    for (int i=1, X, Y; i<=D; i++) {
        cin >> X >> Y;
        st.erase({X-1+dis[S[X]], X}); st.erase({Y-1+dis[S[Y]], Y});
        swap(S[X], S[Y]);
        st.insert({X-1+dis[S[X]], X}); st.insert({Y-1+dis[S[Y]], Y});
        cout << st.begin()->first << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }