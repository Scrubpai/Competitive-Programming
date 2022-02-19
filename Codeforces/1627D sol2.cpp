//saarang sol

#include <bits/stdc++.h>
using namespace std;
const int MXN = 1000 * 1000 + 3;
int best_gcd[MXN];
bool in[MXN];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    for(int x, i = 0; i < n; i++) {
        cin >> x; in[x] = true;
    }
    int cnt = 0;
    for(int i = 1; i < MXN; i++) {
        for(int j = i; j < MXN; j += i)
            if(in[j])
                best_gcd[i] = gcd(best_gcd[i], j);
        cnt += best_gcd[i] == i;
    }
    cout << cnt - n << '\n';
    return 0;
}