#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int a, b, c, cnt; cin >> a >> b >> c; a += b; cnt++;
    while (a < c) a += b, cnt++;
    if (cnt > 3) cout << "Who knows...\n";
    else cout << a << '\n';
}