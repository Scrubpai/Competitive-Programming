#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6 + 5;
typedef long long ll;
#define nl '\n'
int N; ll X, tot, h[MM];
void solve(int tc) {
    cin >> N >> X;
    h[1] = N; h[2] = N-1;
    for (int i=3; i<=N; i++) {
        tot += i-2; h[i] = N-i+1;
        if (tot >= X) {
            if (tot == X) swap(h[i], h[i-1]);
            else {
                tot -= (i-2);
                ll dif = X-tot;
                swap(h[i-dif-1], h[i]);
            }
            for (int j=1; j<=N; j++) {
                if (!h[j]) cout << N-j+1 << ' ';
                else cout << h[j] << ' ';
            }
            return;
        }
        swap(h[i], h[i-1]);
    }
    cout << -1 << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }