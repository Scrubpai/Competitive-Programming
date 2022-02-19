#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int N, Q; vector<int> adj[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> Q;
    for (int i=1, a; i<=N; i++) {
        cin >> a;
        adj[a].push_back(i);
    }
    for (int i=1, l, r, x; i<=Q; i++) {
        cin >> l >> r >> x;
        for (int j=1; j*j<x; j++) {
            if (x%j==0) {
                int d1 = j, d2 = x/j, lo1 = lower_bound(adj[d1].begin(), adj[d1].end(), l) - adj[d1].begin(), lo2 = lower_bound(adj[d2].begin(), adj[d2].end(), l) - adj[d2].begin(), hi1 = upper_bound(adj[d1].begin(), adj[d1].end(), r) - adj[d1].begin(), hi2 = upper_bound(adj[d2].begin(), adj[d2].end(), r) - adj[d2].begin();
                if (hi1-lo1>=1 && hi2-lo2>=1) { cout << "YES\n"; goto next; }
            }
        }
        cout << "NO\n";
        next: ;
    }
}