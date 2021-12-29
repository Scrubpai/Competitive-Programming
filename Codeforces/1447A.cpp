#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int n;

void solve(int tc) {

    cin >> n;
    cout << n << nl;
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}