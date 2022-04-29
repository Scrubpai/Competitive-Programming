#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n; vector<int> vis(2*n+2);
    for (int i=1; i<=2*n+1; i++) {
        if (!vis[i]) {
            cout << i << endl;
            int x; cin >> x; vis[x] = 1;
        }
    }
    return 0;
}