#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
#define nl '\n'
struct p { int a, t, i; } problems[MM];
bool cmp (p a, p b) { return a.t < b.t; }
int n, T;
bool check(int num) {
    int tmp = 0, tot = 0;
    for (int i = 1; i <= n; i++) {
        if (problems[i].a >= num && tot + problems[i].t <= T) tmp++, tot += problems[i].t;
    }
    return tmp >= num;
}
void solve(int tc) {
    cin >> n >> T;
    for (int i = 1, a, t; i <= n; i++) {
        cin >> a >> t;
        problems[i] = {a, t, i};
    }
    sort(problems + 1, problems + 1 + n, cmp);
    int k = 0, lo = 1, hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) k = max(k, mid), lo = mid + 1;
        else hi = mid - 1;
    }
    cout << k << nl << k << nl;
    int tmp = k;
    for (int i = 1; i <= n; i++) {
        if (!tmp) break;
        if (problems[i].a >= k) {
            cout << problems[i].i << ' ';
            tmp--;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}