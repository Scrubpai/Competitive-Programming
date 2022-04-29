#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; string t; cin >> n >> t;
    int x = 0, y = 0, d = 1, dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int i=0; i<n; i++) {
        if (t[i] == 'R') d = (d+1)%4;
        else x += dir[d][0], y += dir[d][1];
    }
    cout << x << " " << y << '\n';
}