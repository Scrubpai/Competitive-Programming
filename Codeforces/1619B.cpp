#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    vector<int> like;
    for (int i=1; i*i<=1e9; i++) like.push_back(i*i);
    for (int i=1; i*i*i<=1e9; i++) like.push_back(i*i*i);
    sort(like.begin(), like.end()); like.resize(unique(like.begin(), like.end()) - like.begin());
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << upper_bound(like.begin(), like.end(), n) - like.begin() << '\n';
    }
}