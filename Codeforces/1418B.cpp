#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
#define LL_INF 0x3f3f3f3f3f3f3f3f

int n, a[105], l[105];

void solve(int tc) {

    cin >> n; vector<int> v;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
        if (!l[i]) v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) {
        if (l[i]) cout << a[i] << " ";
        else { cout << v.back() << " "; v.pop_back(); }
    }
    cout << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}