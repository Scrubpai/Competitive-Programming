#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k; vector<int> a(n), b(n); vector<pii> vec;
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) { cin >> b[i]; vec.push_back({a[i], b[i]}); }
        sort(vec.begin(), vec.end());
        for (int i=0; i<n; i++) {
            if (k >= vec[i].first) {
                k += vec[i].second;
            } else break;
        }
        cout << k << '\n';
    }
}