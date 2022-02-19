#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int N, X, h[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> X;
    if ((N-X)%2==1) { cout << -1 << '\n'; return 0; }
    for (int i=1; i<=X+1; i++) h[i] = 0;
    for (int i=X+2; i<=N; i++) h[i] = h[i-1]^1;
    cout << h[1];
    for (int i=2; i<=N; i++) cout << " " << h[i];
    cout << '\n';
}