#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int T, M, l=1, r; string q[MM], x, c;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> T >> M;
    while (T--) {
        cin >> x >> c;
        if (c == "in") q[++r] = x;
        else {
            if (M && l<=r && q[l]==x) l++, M--;
            else if (q[r] == x) r--;
        }
    }
    for (int i=l; i<=r; i++) cout << q[i] << '\n';
}