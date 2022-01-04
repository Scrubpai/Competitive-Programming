#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
ll N;
void solve(int tc) {
    cin >> N;
    for (int i=1; i<=N; i++) {
        if ((1ll*(i+1)*(i+1)+1)/2 >= N) {
            cout << i << nl;
            return;
        }
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }