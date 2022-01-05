#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5 + 5;
#define nl '\n'
int N; ll a[MM], tmp[MM], ans, p[MM];
void solve(int tc) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        tmp[i] = a[i];
    }
    sort(tmp + 1, tmp + 1 + N);
    for (int i = 1; i <= N; i++) {
        if (a[i] > tmp[i]) {
            int idx = upper_bound(tmp + 1, tmp + 1 + N, a[i]) - (tmp + 1);
            p[i]++; p[idx]--;
        } else if (a[i] < tmp[i]) {
            int idx = lower_bound(tmp + 1, tmp + 1 + N, a[i]) - (tmp + 1) + 1;
            p[idx]++; p[i]--;
        }
    }
    for (int i = 1; i <= N; i++) {
        p[i] += p[i-1];
        if (p[i]) ans = max(ans, tmp[i+1] - tmp[i]);
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc; */ for (int t = 1; t <= tc; t++) solve(t); return 0; }