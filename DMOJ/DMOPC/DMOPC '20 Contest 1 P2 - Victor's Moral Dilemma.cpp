#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 1e6 + 5;
int N, D, a[MM], n, psa[MM];

void solve(int tc) {

    cin >> N >> D; int l = 1, r = N;
    for (int i = 1; i <= N; i++) { cin >> a[i]; psa[i] = psa[i-1] + a[i]; }
    for (int i = 1; i <= D; i++) {
        cin >> n;
        if (psa[l+n-1] - psa[l-1] >= psa[r] - psa[l+n-1]) {
            cout << psa[l+n-1] - psa[l-1] << nl;
            l = l+n;
        } else {
            cout << psa[r] - psa[l+n-1] << nl;
            r = l+n-1;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}