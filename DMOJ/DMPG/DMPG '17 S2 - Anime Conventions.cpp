#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long MAXN = numeric_limits<long long>::max();
typedef long long ll;

int N, Q, u, v; string S; int dsu[100001];

int Find(int x) {
    if (dsu[x]==x) return x;
    else return dsu[x] = Find(dsu[x]);
}

void Union(int x, int y) {
    dsu[Find(x)] = Find(y);
}

void solve() {

    cin >> N >> Q;
    for (int i=1; i<=N; i++) dsu[i] = i;

    for (int i=0; i<Q; i++) {
        cin >> S;
        if (S=="A") {
            cin >> u >> v;
            Union(u, v);
        } else {
            cin >> u >> v;
            if (Find(u)==Find(v)) {
                cout << "Y" << endl;
            } else {
                cout << "N" << endl;
            }
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}