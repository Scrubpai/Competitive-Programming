#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 2e5+5, MX = 5e6+5;
#define nl '\n'
#define f first
#define s second
int n, a[MM]; vector<pii> sum[MX+5];
void solve(int tc) {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        for (int j=i-1; j>=1; j--) {
            int s = a[i] + a[j];
            sum[s].emplace_back(make_pair(i, j));
            if (sum[s].size() < 2) continue;
            sort(sum[s].begin(), sum[s].end());
            do {
                int a = sum[s][0].f, b = sum[s][0].s, c = sum[s][1].f, d = sum[s][1].s;
                if (a != b && a != c && a != d && b != c && b != d && c != d) {
                    cout << "YES" << nl;
                    cout << a << " " << b << " " << c << " " << d << nl;
                    return;
                }
            } while(next_permutation(sum[s].begin(), sum[s].end()));
        }
    }
    cout << "NO" << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }