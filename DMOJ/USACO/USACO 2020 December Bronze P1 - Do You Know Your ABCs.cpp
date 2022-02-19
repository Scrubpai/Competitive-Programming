#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    vector<int> x(7);
    for (int i=0; i<7; i++) cin >> x[i];
    sort(x.begin(), x.end());
    cout << x[0] << " " << x[1] << " " << x[6]-x[0]-x[1] << '\n';
}