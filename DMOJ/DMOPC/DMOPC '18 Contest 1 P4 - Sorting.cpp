#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define nl '\n'

const int MM = 2e5 + 5;
ll N, M, K, X, psa[MM]; pii f[MM]; int ans[MM];

void solve(int tc) {

    cin >> N >> M >> K >> X;
    for (int i = 1; i <= N; i++) {
        cin >> f[i].first; f[i].second = i;
    }
    sort(f + 1, f + 1 + N);
    for (int i = 1; i <= N; i++) psa[i] = psa[i-1] + f[i].first;
    int lft = 0, rit = N;
    //lft is the biggest number that can occupy position K
    //rit is the smallest number that can occupy position K
    while (lft <= N && psa[lft] < K) lft++;
    while (rit >= 1 && psa[N] - psa[rit-1] < K) rit--;
    if (X > lft || X < N - rit + 1) {
        cout << -1 << nl; return;
    }
    int idx = 0;
    for (int i = X; i <= N; i++) {
        if (psa[i] - psa[i-X] >= K) {
            for (int j = i - X + 1; j <= i; j++) ans[f[j].second] = ++idx;
            for (int j = 1; j <= N; j++) {
                if (!ans[j]) ans[j] = ++idx;
                cout << ans[j] << " ";
            }
            cout << nl; return;
        }
    }
    cout << -1 << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}