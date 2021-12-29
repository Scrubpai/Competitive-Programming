#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
string a, b, c; int pa, pb, pc, cur;
void solve(int tc) {
    cin >> a >> b >> c;
    while (1) {
        if (cur == 0) {
            if (pa >= a.size()) { cout << 'A'; return; }
            cur = a[pa] - 'a'; pa++;
        } else if (cur == 1) {
            if (pb >= a.size()) { cout << 'B'; return; }
            cur = b[pb] - 'a'; pb++;
        } else {
            if (pc >= c.size()) { cout << 'C'; return; }
            cur = c[pc] - 'a'; pc++;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}