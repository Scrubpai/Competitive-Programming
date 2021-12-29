#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
int m, R;
void solve(int tc) {
    cin >> m >> R;
    double ans = 1.0*2*R*m;
    for (int i=1; i<m; i++) {
        //traverse "2*R*i"
        double num = 1.0*2*(m-i); //number of pairs of circles
        if (i==1) ans += 1.0*R*(2+sqrt(2))*num;
        else ans += 1.0*R*(2*(i-1) + 2*sqrt(2))*num;
    }
    ans /= (1.0*m*m);
    printf("%.9f\n", ans);
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }