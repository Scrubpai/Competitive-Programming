#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5 + 5;
int n;

void solve(int tc) {

    cin >> n;
    cout << 2 << nl;
    cout << n << " " << n - 1 << nl;
    for (int i = n - 2; i >= 1; i--) cout << i << " " << i + 2 << nl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}