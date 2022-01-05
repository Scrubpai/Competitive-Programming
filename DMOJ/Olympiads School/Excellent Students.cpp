#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))
#define INF 0x3f3f3f3f

const int MM = 5e5 + 5;
struct ranks {
    int a, b, c; //a - round 1, b - round 2, c - round 3
} rk[MM];
bool cmp(ranks a, ranks b) { return a.a < b.a; }
int n, bit[MM];

void update(int p, int v) {
    for (; p <= n; p += p&-p) bit[p] = min(bit[p], v);
}

int query(int p) {
    int ret = INF;
    for (; p >= 1; p -= p&-p) ret = min(ret, bit[p]);
    return ret;
}

void solve(int tc) {

    cin >> n; ms(bit, INF);
    /*
     * students are already sorted by their rank in round 1. student i is better than student j if b[i] < b[j] and c[i] < c[j]
     * bit[i]: lowest c value from rank 1 to rank i
     */
    for (int k = 1; k <= 3; k++) {
        for (int i = 1, stu; i <= n; i++) {
            cin >> stu;
            if (k == 1) rk[stu].a = i;
            else if (k == 2) rk[stu].b = i;
            else rk[stu].c = i;
        }
    }
    sort(rk + 1, rk + 1 + n, cmp);
    int ans = n;
    for (int i = 1; i <= n; i++) {
        int lo = query(rk[i].b);
        if (rk[i].c > lo) ans--;
        update(rk[i].b, rk[i].c);
    }
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}