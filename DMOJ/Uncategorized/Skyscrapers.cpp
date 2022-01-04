#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5, MV = 2e4;
#define nl '\n'
int M, N, c, C, row[MM], col[MM], cntr[MV+1], cntc[MV+1], maximum, minimum;
void solve(int tc) {
    cin >> M >> N >> c >> C;
    for (int i=0; i<M; i++) { cin >> row[i]; cntr[row[i]]++; }
    for (int i=0; i<N; i++) { cin >> col[i]; cntc[col[i]]++; }
    sort(row, row+M); sort(col, col+N);
    if (row[M-1] != col[N-1]) { cout << "Impossible" << nl; return; }
    for (int i=0, j=0; i<M; i++) {
        while (j<N && col[j] <= row[i]) {
            maximum += col[j] * (M-i) * C;
            j++;
        }
        maximum += row[i] * (N-j) * C;
    }
    for (int i=1; i<=MV; i++) minimum += c * i * max(cntr[i], cntc[i]);
    printf("Minimum: %d, maximum: %d\n", minimum, maximum);
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }