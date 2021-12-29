#include <bits/stdc++.h>
using namespace std;
int N, Q;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> Q; vector<int> d;
    for (int i=0, x, y; i<N; i++) {
        cin >> x >> y;
        double r = sqrt(1ll*x*x+1ll*y*y); d.push_back(ceil(r));
    }
    sort(d.begin(), d.end());
    for (int i=0, r; i<Q; i++) {
        cin >> r;
        cout << upper_bound(d.begin(), d.end(), r) - d.begin() << '\n';
    }
    return 0;
}