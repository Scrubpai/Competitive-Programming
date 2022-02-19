#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int H, S, Q; cin >> H >> S >> Q;
    for (int i=1; i<=Q; i++) {
        H-=S;
        cout << H << '\n';
    }
}