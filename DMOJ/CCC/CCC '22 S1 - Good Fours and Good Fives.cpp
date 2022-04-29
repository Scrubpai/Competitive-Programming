#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    int ans = 0;
    for (int i=0; i*4<=N; i++) {
        int j = N-i*4;
        if (j%5==0) ans++;
    }
    cout << ans << '\n';
}