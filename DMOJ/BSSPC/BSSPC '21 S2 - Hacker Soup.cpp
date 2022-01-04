#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
typedef pair<int, int> pi;
struct event { int a, b, c, d; };
int N, K, Q; vector<event> queries;
ll dfs(int y, int x, int i) {
    if (i < 0) return 1ll*(y-1)*N+x;
    event e = queries[i];
    int n = e.c-e.a+1;
    if (y >= e.a && y <= e.c && x >= e.b && x <= e.d) {
        y = y-e.a+1; x = x-e.b+1;
        x=n-x+1;
        swap(y,x);
        y = y+e.a-1; x = x+e.b-1;
        return dfs(y, x, i-1);
    } else return dfs(y, x, i-1);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K >> Q;
    for (int i=1, a, b, c, d; i<=K; i++) {
        cin >> a >> b >> c >> d;
        queries.push_back({a, b, c, d});
    }
    for (int i=1, r, c; i<=Q; i++) {
        cin >> r >> c;
        cout << dfs(r, c, K-1) << '\n';
    }
}