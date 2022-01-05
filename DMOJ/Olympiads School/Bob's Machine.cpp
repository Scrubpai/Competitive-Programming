#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6 + 5;
#define nl '\n'
struct interval { int s, e, v; };
bool cmp(interval a, interval b) { return a.e < b.e; }
int N, M, R, bit[MM]; ll dp[1005]; interval arr[1005];
void update(int p, int i) { for (; p <= N; p += p&-p) bit[p] = max(bit[p], i); }
int query(int p) { int ret = 0; for (; p >= 1; p -= p&-p) ret = max(ret, bit[p]); return ret; }
void solve(int tc) {
    cin >> N >> M >> R;
    for (int i = 1, s, e, v; i <= M; i++) { cin >> s >> e >> v; arr[i] = {s, e, v}; }
    sort(arr + 1, arr + 1 + M, cmp);
    for (int i = 1; i <= M; i++) {
        dp[i] = max(dp[i-1], dp[query(arr[i].s - R)] + arr[i].v);
        update(arr[i].e, i);
    }
    cout << dp[M];
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}