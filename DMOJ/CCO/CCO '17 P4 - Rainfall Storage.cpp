#include <bits/stdc++.h>
using namespace std;
const int MM = 505;
#define nl '\n'
int N, h[MM]; bool dp[2][MM*50]; unordered_set<int> st;
void solve(int tc) {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> h[i];
    sort(h, h+N, greater<int>());
    dp[0][0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= h[0]*N; j++) dp[1][j] = dp[0][j];
        for (int pre : st) {
            int diff = pre - h[i];
            for (int j = 0; j <= h[0]*N - diff; j++) {
                if (dp[0][j]) dp[1][j+diff] = 1;
            }
        }
        for (int j = 0; j <= h[0]*N; j++) dp[0][j] = dp[1][j];
        st.insert(h[i]);
    }
    for (int j = 0; j <= h[0]*N; j++) {
        if (dp[0][j]) cout << j << " ";
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc; */ for (int t = 1; t <= tc; t++) solve(t); return 0; }