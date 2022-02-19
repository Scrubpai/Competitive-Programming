#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    double M; cin >> M;
    double t1 = (5-sqrt(48*M-23))/24, t2 = (5+sqrt(48*M-23))/24;
    if (t1>0) cout << fixed << setprecision(6) << t1 << '\n';
    else cout << fixed << setprecision(6) << t2 << '\n';
}