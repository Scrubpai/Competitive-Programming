#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;

ll a, b, c;

void solve(int tc) {

    cin >> a >> b >> c;
    cout << a + b + c - 1 << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}