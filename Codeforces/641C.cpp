#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n, q, odd, even, op, x;
void solve(int tc) {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &x);
            x %= n;
            odd = (odd + x + n) % n;
            even = (even + x + n) % n;
        } else {
            if (even % 2 == 1) even = (even - 1 + n) % n;
            else even = (even + 1) % n;
            if (odd % 2 == 1) odd = (odd + 1) % n;
            else odd = (odd - 1 + n) % n;
        }
    }
    for (int i = 0; i < n; i++) {
        if (((i-odd+n)%n) % 2 == 1) cout << (i-odd+n)%n + 1 << ' ';
        else cout << (i-even+n)%n + 1 << ' ';
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}