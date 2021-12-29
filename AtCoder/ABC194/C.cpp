#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
int N, freq[405];
void solve(int tc) {
    cin >> N;
    for (int i=1, a; i<=N; i++) {
        cin >> a;
        freq[a+200]++;
    }
    ll ans = 0;
    for (int i=0; i<=400; i++) {
        for (int j=0; j<i; j++) {
            ans += 1ll * freq[i] * freq[j] * (i-j) * (i-j);
        }
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }