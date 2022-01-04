#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long MAXN = numeric_limits<long long>::max();
typedef long long ll;

struct Pair {
    int x, y, r;
};

int B, Q, x, y, r, a, b;
vector<int> adj[10001];
Pair arr[10001];
bool vis[10001];

bool bfs(int start, int finish) {

    queue<int> Q; for (int i=1; i<=B; i++) vis[i] = false;
    Q.push(start); vis[start] = true;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (int v : adj[cur]) {
            if (!vis[v]) {
                Q.push(v); vis[v] = true;
            }
        }
    }
    if (vis[finish]) return true;
    else return false;

}

void solve() {

    cin >> B>> Q;

    for (int i=1; i<=B; i++) {
        cin >> x >> y >> r;
        arr[i] = {x, y, r};
    }

    for (int i=1; i<=B; i++) {
        for (int j=1; j<=B; j++) {
            if (i!=j && (arr[i].r*arr[i].r)>=(pow(arr[j].x-arr[i].x, 2) + pow(arr[j].y-arr[i].y, 2))) {
                adj[i].push_back(j);
            }
        }
    }

    for (int i=0; i<Q; i++) {
        cin >> a >> b;
        if (bfs(a, b)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}