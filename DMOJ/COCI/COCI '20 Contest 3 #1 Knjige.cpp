#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
struct moves { string s, a, b; };
int n, d[105], d2[105]; vector<moves> res;
void solve(int tc) {
    cin >> n;
    deque<int> dq1, dq2;
    for (int i=1; i<=n; i++) {
        cin >> d[i]; d2[i] = d[i];
        dq1.push_back(d[i]);
    }
    while (!dq1.empty()) {
        res.push_back({"UZMI", "L", "L"});
        res.push_back({"STAVI", "L", "D"});
        dq2.push_front(dq1.front());
        dq1.pop_front();
    }
    sort(d2+1, d2+1+n);
    for (int i=n; i>=1; i--) {
        while (dq2.front() != d2[i]) {
            res.push_back({"UZMI", "L", "D"});
            res.push_back({"STAVI", "L", "L"});
            dq1.push_front(dq2.front());
            dq2.pop_front();
        }
        res.push_back({"UZMI", "D", "D"});
        dq2.pop_front();
        while (dq1.size() > n-i) {
            res.push_back({"UZMI", "L", "L"});
            res.push_back({"STAVI", "L", "D"});
            dq2.push_front(dq1.front());
            dq1.pop_front();
        }
        dq1.push_front(d2[i]);
        res.push_back({"STAVI", "D", "L"});
    }
    cout << res.size() << nl;
    for (moves m : res) {
        cout << m.s << " " << m.a << " " << m.b << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }