#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n;
void solve(int tc) {
    while (true) {
        cin >> n;
        if (!n) return;
        vector<int> a;
        int x; cin >> x;
        for (int i=0; i<n-1; i++) {
            int y; cin >> y;
            a.push_back(y-x); x=y;
        }
        if (n==1) { cout << 0 << nl; continue; }
        for (int cycle = 1; cycle <= n-1; cycle++) {
            bool flag = 1;
            for (int i=cycle; i<n-1; i++) {
                if (a[i] != a[i%cycle]) { flag = false; break; }
            }
            if (flag) { cout << cycle << nl; break; }
        }
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }