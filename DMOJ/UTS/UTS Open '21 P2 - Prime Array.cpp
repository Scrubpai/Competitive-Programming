#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int K, N, a[105]; vector<int> v;
void solve(int tc) {
    cin >> K;
    int tot = 0;
    for (int i=2; ; i++) {
        bool flag = 1;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            v.push_back(i);
            if (v.size() == 100) break;
        }
    }
    reverse(v.begin(), v.end());
    for (int i=1; ; i++) {
        tot += i; N++;
        a[i] = 1;
        if (tot >= K) break;
    }
    int rem = tot - K;
    if (rem != 0) {
        for (int i=1; i<=rem; i++) {
            a[i] = v.back(); v.pop_back();
        }
    }
    cout << N << nl;
    for (int i=1; i<=N; i++) cout << a[i] << ' ';
    cout << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }