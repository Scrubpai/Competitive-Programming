#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N, M, A[3005], B[105], dp[2][3005][105][105];
int fun(int pos, int l, int r, int flag) {
    if (dp[flag][pos][l][r] > 0) return dp[flag][pos][l][r];
    int best = 0;
    if (pos <= N) {
        best = max(best, fun(pos+1, l, r, 1));
        if (flag) {
            best = max(best, fun(pos+1, l, r, 0) + A[pos]);
        }
    }
    if (l <= r) {
        best = max(best, fun(pos, l+1, r, 1));
        if (flag) {
            best = max(best, fun(pos, l, r-1, 0) + B[r]);
        }
    }
    return dp[flag][pos][l][r] = best;
}
void solve(int tc) {
    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    cin >> M;
    for (int i=1; i<=M; i++) cin >> B[i];
    sort(B + 1, B + 1 + M);
    cout << fun(1, 1, M, 1) << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }