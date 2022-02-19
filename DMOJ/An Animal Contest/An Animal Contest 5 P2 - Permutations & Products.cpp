#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
ll N, ans[MM], p[MM], mn=1e9, mx;
ll ask(int x, int y) {
    cout << "? " << x << " " << y << '\n' << flush;
    ll ret; cin >> ret; return ret;
}
void output() {
    cout << '!';
    for (int i=1; i<=N; i++) cout << ' ' << ans[i];
    cout << '\n' << flush;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=2; i<=N; i++) {
        p[i] = ask(1, i);
        mx = max(mx, p[i]); mn = min(mn, p[i]);
    }
    if (mx == N) ans[1] = 1;
    else ans[1] = mn;
    for (int i=2; i<=N; i++) ans[i] = p[i]/ans[1];
    output();
    return 0;
}