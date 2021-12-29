#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int S, F;
int get(int x) {
    int ret = ((x+1)/2)%2==1?1:0;
    for (int i=1; i<30; i++) {
        if ((x/(1<<i))%2==1 && (x%(1<<i))%2==0) ret += (1<<i);
    }
    return ret;
}
void solve(int tc) {
    cin >> S >> F;
    int A = get(F), B = get(S-1), C = A^B;
    cout << C << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }