#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int N, a, odd, even;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> a;
        if (a&1) odd++;
        else even++;
    }
    cout << odd/2 + even/2 << '\n';
}