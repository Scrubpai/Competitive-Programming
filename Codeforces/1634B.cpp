/* Idea:
 *
 * Key observation 1: a+b and a⊕b will always have the same parity
 * Key observation 2: Therefore, either Alice or Bob will be unable to get y regardless of the order of the operations
 *
 * x and x+3 have different parity. Therefore, after all operations, they will also have different parities. So check the parity of the result with the parity of y.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; ll x, y; cin >> n >> x >> y;
        for (int i=1, a; i<=n; i++) { cin >> a; x += a; }
        if (x%2==y%2) cout << "Alice\n";
        else cout << "Bob\n";
    }
}