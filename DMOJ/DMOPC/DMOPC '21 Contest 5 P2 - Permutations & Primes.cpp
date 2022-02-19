#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    if (n==1) cout << 1 << '\n';
    else if (n==2) cout << -1 << '\n';
    else {
        cout << 1 << " " << 3 << " " << 2;
        for (int i=4; i<=n; i++) cout << " " << i;
        cout << '\n';
    }
}