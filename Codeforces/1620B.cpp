#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        ll w, h, k; cin >> w >> h;
        vector<ll> x[2], y[2];
        for (int i=0; i<4; i++) {
            cin >> k;
            for (int j=0, v; j<k; j++) {
                cin >> v;
                if (i>1) y[i%2].push_back(v);
                else x[i%2].push_back(v);
            }
        }
        cout << max(max(x[0][x[0].size()-1] - x[0][0], x[1][x[1].size()-1] - x[1][0]) * h, max(y[0][y[0].size()-1] - y[0][0], y[1][y[1].size()-1] - y[1][0]) * w) << '\n';
    }
}