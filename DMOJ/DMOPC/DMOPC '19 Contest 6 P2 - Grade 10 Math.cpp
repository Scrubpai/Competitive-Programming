#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 1e6+6;
#define nl '\n'
int a, b, fa[MM], fb[MM]; vector<int> p;
void solve(int tc) {
    cin >> a >> b;
    for (int i=2; i<=sqrt(a); i++) {
        if (a%i==0) p.push_back(i);
        while (a%i==0) {
            a/=i; fa[i]++;
        }
    }
    if (a>1) fa[a]++, p.push_back(a);
    for (int i=2; i<=b; i++) {
        int tmp = i;
        for (int v : p) {
            while (tmp%v==0) tmp/=v, fb[v]++;
        }
    }
    int ans = 1e9;
    for (int v : p) ans = min(ans, fb[v] / fa[v]);
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }