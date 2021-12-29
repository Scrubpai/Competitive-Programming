#include <bits/stdc++.h>
using namespace std;
int N, cnt[4]; double dp[305][305][305];
double fun(int i, int j, int k) {
    if (i < 0 || j < 0 || k < 0) return 0;
    if (i == 0 && j == 0 && k == 0) return 0;
    if (dp[i][j][k] > 0) return dp[i][j][k];
    dp[i][j][k] = 1.0*(N + i*fun(i-1, j, k) + j*fun(i+1, j-1, k) + k*fun(i, j+1, k-1)) / (i+j+k);
    return dp[i][j][k];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1, a; i<=N; i++) {
        cin >> a;
        cnt[a]++;
    }
    printf("%.9f\n", fun(cnt[1], cnt[2], cnt[3]));
}