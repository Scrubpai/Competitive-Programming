#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
#define nl '\n'
int T, N, M, P, Q, K, D; string S;
void solve(int tc) {
    cin >> T;
    while (T--) {
        cin >> N;
        map<string, vector<pi>> mp;
        for (int i=0; i<N; i++) {
            cin >> M;
            for (int j=0; j<M; j++) {
                cin >> S >> P >> Q;
                mp[S].push_back({P, Q});
            }
        }
        int ans = 0;
        cin >> K;
        for (int i=0; i<K; i++) {
            cin >> S >> D;
            sort(mp[S].begin(), mp[S].end());
            for (int j=0; j<mp[S].size() && D>0; j++) {
                tie(P, Q) = mp[S][j];
                ans += P * min(D, Q);
                D -= Q;
            }
        }
        cout << ans << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(tc); return 0; }