#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N;
void solve(int tc) {
    cin >> N;
    for (int i=2; i<=sqrt(N) && N>1; i++) {
        while (N%i==0) { N/=i; cout << i << " "; }
    }
    if (N>1) cout << N << " ";
    cout << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(tc); return 0; }