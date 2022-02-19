#include <bits/stdc++.h>
using namespace std;
int N, i, j;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> i >> j;
    if (abs(i*i-N) < abs(j*j-N)) cout << 1 << '\n';
    else cout << 2 << '\n';
}