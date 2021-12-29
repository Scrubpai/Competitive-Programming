#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e7;
#define nl '\n'
int t, c, d, x, nxt[MM+5], num[MM+5], p[10];
void sieve() {
    for (int i=2; i<=MM; i++) {
        if (nxt[i] == 0) {
            nxt[i] = i;
            if (1ll*i*i > MM) continue;
            for (int j=i*i; j<=MM; j+=i) {
                if (nxt[j] == 0) nxt[j] = i;
            }
        }
    }
}
void primefactor(int n) {
    int tmp = n;
    while (n > 1) {
        int div = nxt[n];
        while (div == nxt[n]) n /= nxt[n];
        num[tmp]++;
    }
}
void solve(int tc) {
    cin >> t;
    sieve();
    p[0] = 1;
    for (int i=1; i<=MM; i++) {
        primefactor(i);
        if (i<=10) p[i] = p[i-1] * 2;
    }
    while (t--) {
        cin >> c >> d >> x;
        int ans = 0;
        for (int i=1; i<=(int)sqrt(x); i++) {
            if (x % i == 0) {
                int g = i;
                if (((x/g)+d)%c == 0) {
                    int k = ((x/g)+d)/c;
                    ans += p[num[k]];
                }
                if (g != x/i) {
                    g = x/i;
                    if (((x/g)+d)%c==0) {
                        int k = ((x/g)+d)/c;
                        ans += p[num[k]];
                    }
                }
            }
        }
        cout << ans << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }