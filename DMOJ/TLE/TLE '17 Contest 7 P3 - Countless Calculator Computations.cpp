#include <bits/stdc++.h>
using namespace std;
const double acc = 0.00001;
int Q, Y, Z;
double calc(double x, int y) {
    double t = 1;
    for (int i=0; i<y; i++) {
        t = pow(x, t);
    }
    return t;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> Q;
    while (Q--) {
        cin >> Y >> Z;
        double lo = 1, hi = 10;
        while (hi - lo > acc) {
            double mid = (lo + hi) / 2, cur = calc(mid, Y);
            if (abs(cur - Z) <= acc) break;
            else if (cur > Z) hi = mid;
            else lo = mid;
        }
        cout << fixed << setprecision(20) << lo << '\n';
    }
    return 0;
}