#include <bits/stdc++.h>
using namespace std;
const int MM = 1e7;
#define nl '\n'
bool p[MM+1];
void sieve() {
    p[1] = true;
    for (int i=2; i*i<=MM; i++) {
        if (!p[i]) {
            for (int j=i*i; j<=MM; j+=i) p[j] = true;
        }
    }
}
void solve(int tc) {
    sieve();
    for (int t=0, n; t<5; t++) {
        cin >> n;
        if (!p[n]) { printf("%d = %d\n", n, n); continue; }
        if (n % 2 == 1) {
            bool flag = false;
            for (int i=n/3; i && !flag; i--) {
                if (p[i]) continue;
                for (int j=(n-i)/2; j>=i && !flag; j--) {
                    if (p[j]) continue;
                    if (!p[n-i-j]) { printf("%d = %d + %d + %d\n", n, i, j, n-i-j); flag = true; }
                }
            }
        } else {
            for (int i=n/2; i; i--) {
                if (!p[i] && !p[n-i]) { printf("%d = %d + %d\n", n, i, n-i); break; }
            }
        }
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(tc); return 0; }